#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QApplication>
#include <QFile>
#include <QDebug>

class CommonHelper
{
public:
    static void setStyle(const QString &style)
    {
        QFile qss(style);
        if(!qss.open(QFile::ReadOnly))
        {
            qDebug() << "qss file open failed";
            return;
        }
        qApp->setStyleSheet(qss.readAll()); // QT中自带的单例
        qss.close();
    }
};

#endif // COMMONHELPER_H
