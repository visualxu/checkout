#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include"createdatabase.h"
//#include<QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout<<"haha";
    ui->tableWidget->verticalHeader()->setHidden(true);//去掉自带的行号（相当反人类的自带）
    ui->tableWidget->horizontalHeader()->setHidden(true);//去掉自带的列号（同上）
    ui->tableWidget->setRowCount(4);//设置表格行数
    ui->tableWidget->setColumnCount(5);//设置表格列数
    ui->tableWidget->setSpan(0, 1, 1, 2);
    ui->tableWidget->setSpan(1, 0, 2, 1);
    ui->tableWidget->setSpan(1, 1, 2, 1);
    ui->tableWidget->setSpan(1, 4, 3, 1);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("序号"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("校准项目"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("结论"));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem("备注"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("通用技术要求"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("外观和通电检查"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("绝缘电阻"));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("2"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("互感器负荷箱负荷示值"));
    ui->tableWidget->setItem(3,2,new QTableWidgetItem("有功分量和无功分量"));
    for (int i = 0;i < 4;i++) {//将表中关键字设置为只读，加阴影
        for (int j = 0;j < 5;j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i,j);
            if (item) {
                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
                item->setBackground(QBrush(QColor(Qt::lightGray)));
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
//                ui->tableWidget->setItem(i,1,item);

            }}
    }
    ui->tableWidget->setStyleSheet("QTableWidget::item{border:1px solid ;}");//表格线加粗
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//水平方向自适应
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//垂直方向自适应
}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()//保存数据
{
    createdata db;
    QSqlQuery query = db.createbase();
}

void MainWindow::on_pushButton_clicked()//打印报表
{

}
