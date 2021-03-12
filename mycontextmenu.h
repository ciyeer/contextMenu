#ifndef MYCONTEXTMENU_H
#define MYCONTEXTMENU_H

#include <QWidget>
#include <QContextMenuEvent>

namespace Ui {
class MyContextMenu;
}

class MyContextMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MyContextMenu(QWidget *parent = nullptr);
    ~MyContextMenu();

private:
    virtual void contextMenuEvent(QContextMenuEvent *) override;

private:
    Ui::MyContextMenu *ui;
    QAction * colorChat;
};

#endif // MYCONTEXTMENU_H
