#include "mainwindow.h"
#include"createdatabase.h"
#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>
#include<QStringList>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList driver = QSqlDatabase::drivers();
    foreach(QString driver,driver) {
        qDebug()<<driver;
    }
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    createdata db;//建库
    db.createbase();
    MainWindow w;
    w.show();
    return a.exec();
}
