#include "mycontextmenu.h"
#include "ui_mycontextmenu.h"
#include <QMenu>
#include <QFile>
#include <QAction>
#include <QString>
#include <QDebug>

MyContextMenu::MyContextMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyContextMenu)
{
    ui->setupUi(this);

    QFile file("C:/Users/cymer/Desktop/20121/Qt/day2/Test/contextMenu/contextmenu.css");
    file.open(QFile::ReadOnly);//读取qss文件，设置样式
    if(file.isOpen())
    {
        QString qss = file.readAll();
        //qDebug()<<qss;
        this->setStyleSheet(qss);
    }
    file.close();

    //带选择的QAction应该设置为类的成员变量，以便存住当前状态
    colorChat = new QAction(QString::fromLocal8Bit("   使用多彩气泡"),this);
    colorChat->setCheckable(true);
    colorChat->setChecked(true);
    colorChat->setIcon(QIcon(":/choose.png"));
    connect(colorChat,&QAction::triggered,this,[=]()
    {
        if(colorChat->isChecked())
            colorChat->setIcon(QIcon(":/choose.png"));
        else
            colorChat->setIcon(QIcon(":/space.png"));
    });
}

MyContextMenu::~MyContextMenu()
{
    delete ui;
}

void MyContextMenu::contextMenuEvent(QContextMenuEvent *event)
{
    QAction * start = new QAction(QStringLiteral("   复制"),this);
    QAction * allchoose = new QAction(QStringLiteral("   全部选择"),this);
    QAction * choosesome = new QAction(QStringLiteral("   多选"),this);
    choosesome->setIcon(QIcon(":/duoxuankuang.png"));
    QAction * showType = new QAction(QStringLiteral("   显示比例"),this);
    QAction * setColorChat = new QAction(QStringLiteral("   设置多彩气泡"),this);
    QAction * quit = new QAction(QStringLiteral("   清屏"),this);

    QMenu * m = new QMenu(this);
    m->setFixedWidth(100);
    m->addAction(new QAction("  200%"));
    m->addAction(new QAction("  180%"));
    m->addAction(new QAction("  160%"));
    m->addAction(new QAction("  140%"));
    m->addAction(new QAction("  120%"));
    m->addAction(new QAction("  100%"));
    m->setTitle(QStringLiteral("   显示比例"));

    QMenu * menu = new QMenu(this);
    menu->setFixedWidth(200);
    menu->addAction(start);
    menu->addAction(allchoose);
    menu->addAction(choosesome);
    menu->addMenu(m);
    menu->addSeparator();
    menu->addAction(showType);
    menu->addAction(colorChat);
    menu->addAction(setColorChat);
    menu->addSeparator();
    menu->addAction(quit);

    menu->exec(QCursor::pos());

    return QWidget::contextMenuEvent(event);
}
