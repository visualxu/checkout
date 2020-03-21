#include "mainwindow.h"

#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>
#include<QStringList>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList driver = QSqlDatabase::drivers();
    foreach(QString driver,driver) {
        qDebug()<<driver;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
