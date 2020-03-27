#ifndef CREATETAB2_H
#define CREATETAB2_H

#endif // CREATETAB2_H
#include<mainwindow.h>
#include<QSqlQuery>
#include<QMainWindow>
class createtab2 {
public :
    int num;//行数.误差数*3
    int id;//出厂编号
    void ctab2(Ui::MainWindow *ui);
    void store(Ui::MainWindow *ui);
};
