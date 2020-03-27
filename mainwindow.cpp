#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<stdio.h>
#include<QDebug>
#include<QTextCodec>
#include"createtab2.h"
#include"createdatabase.h"
#include"to_execl.h"
//#include<QTableWidgetItem>
createtab2 tab2;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    std::cout<<"haha";
    tab2.num = 15;//5条误差数据
    tab2.ctab2(ui);
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
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));//不可修改
//                ui->tableWidget->setItem(i,1,item);
            }
            else {
                ui->tableWidget->setItem(i,j,new QTableWidgetItem());
                QTableWidgetItem *item1 = ui->tableWidget_2->item(i,j);
                //item1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
            }
        }
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
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForLocale(codec);
      // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
//    createdata db;
    QSqlQuery query;
    QString unit = ui->comboBox->currentText().toUtf8();//单位
    QString address = ui->lineEdit_2->text().toUtf8();//地址
    QString machinename = ui->comboBox_2->currentText().toUtf8();//仪器名称
    QString model = ui->comboBox_3->currentText().toUtf8();//型号
    QString factory = ui->comboBox_4->currentText().toUtf8();//工厂
    QString id = ui->lineEdit_3->text().toUtf8();//出厂编号
    QString generatedate = ui->dateEdit->text().toUtf8();//生产日期
    QString accuratelevel = ui->comboBox_18->currentText().toUtf8();//精准度
    QString Cos = ui->lineEdit_23->text().toUtf8();//功率因素
    QString kva = ui->lineEdit_22->text().toUtf8();//额定容量
    QString VDC = ui->lineEdit_21->text().toUtf8();//电压范围
    QString ratedvoltage = ui->lineEdit_20->text().toUtf8();//额定电压
    QString testvoltage = ui->lineEdit_19->text().toUtf8();//试验电压
    QString ratefrequency = ui->lineEdit_18->text().toUtf8();//额定频率
    QString certificatenumber = ui->lineEdit_17->text().toUtf8();//证书编号
    QString Calibrationbasis = ui->comboBox_17->currentText().toUtf8();//校准依据
    QString Calibrationaddress = ui->comboBox_23->currentText().toUtf8();//校准地点
    QString temperature = ui->lineEdit_14->text().toUtf8();//温度
    QString humidity = ui->lineEdit_16->text().toUtf8();//湿度
    QString Calibrationdate = ui->dateEdit_2->text().toUtf8();//校准日期
    QString effectivedate = ui->dateEdit_3->text().toUtf8();//有效日期
    QString checkedby = ui->comboBox_22->currentText().toUtf8();//核验员
    QString checkoperator = ui->comboBox_21->currentText().toUtf8();//校验员
    QString jielun1 = ui->tableWidget->item(1,3)->text();
    qDebug()<<"haha";
    QString jielun2 = ui->tableWidget->item(2,3)->text();
    QString jielun3 = ui->tableWidget->item(3,3)->text();
    QString remark = ui->tableWidget->item(1,4)->text();
    qDebug()<<"haha";
    query.prepare("insert into list(出厂编号,委托单位,地址,仪器名称,型号规格,制造厂家,生产日期,准确度级别,功率因素,额定容量,电压范围,额定电压,试验电压,额定频率,"
                  "证书编号,校准依据,校准地点,环境温度,相对湿度,校准日期,有效日期,校验员,核验员,外观和通电检查,绝缘电阻,有功分量和无功分量,备注)"
                  "values"
                  "(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,id.toInt());
    qDebug()<<unit;
    query.bindValue(1,unit);
    query.bindValue(2,address);
    query.bindValue(3,machinename);
    query.bindValue(4,model);
    query.bindValue(5,factory);
    query.bindValue(6,generatedate);
    query.bindValue(7,accuratelevel);
    query.bindValue(8,Cos.toFloat());//功率因素
    query.bindValue(9,kva);
    query.bindValue(10,VDC);
    query.bindValue(11,ratedvoltage);
    query.bindValue(12,testvoltage.toInt());//试验电压
    query.bindValue(13,ratefrequency.toInt());//额定频率
    query.bindValue(14,certificatenumber);
    query.bindValue(15,Calibrationbasis);
    query.bindValue(16,Calibrationaddress);
    query.bindValue(17,temperature.toInt());//温度
    query.bindValue(18,humidity.toInt());//湿度
    query.bindValue(19,Calibrationdate);
    query.bindValue(20,effectivedate);
    query.bindValue(21,checkedby);
    query.bindValue(22,checkoperator);
    query.bindValue(23,jielun1);
    query.bindValue(24,jielun2);
    query.bindValue(25,jielun3);
    query.bindValue(26,remark);
    query.exec();
    tab2.id = id.toInt();
    qDebug()<<tab2.id;
    tab2.store(ui);
}

void MainWindow::on_pushButton_clicked()//打印报表
{
    to_execl toe;
    toe.to_exec(ui);
}
