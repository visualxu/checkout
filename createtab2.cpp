#include "createtab2.h"
#include "ui_mainwindow.h"
void createtab2::ctab2(Ui::MainWindow *ui)
{//创建TAB_2窗口
    int rowindex = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->setColumnCount(11);
    ui->tableWidget_2->horizontalHeader()->setHidden(true);
    ui->tableWidget_2->verticalHeader()->setHidden(true);
    ui->tableWidget_2->setRowCount(rowindex + 3);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setSpan(0,0,1,11);
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem("负荷示值校准"));
    ui->tableWidget_2->setSpan(1,0,2,1);
    ui->tableWidget_2->setItem(1,0,new QTableWidgetItem("序号"));
    ui->tableWidget_2->setSpan(1,1,2,1);
    ui->tableWidget_2->setItem(1,1,new QTableWidgetItem("标称负荷(VA)"));
    ui->tableWidget_2->setSpan(1,2,2,1);
    ui->tableWidget_2->setItem(1,2,new QTableWidgetItem("功率因素"));
    ui->tableWidget_2->setSpan(1,3,2,1);
    ui->tableWidget_2->setItem(1,3,new QTableWidgetItem("额定电压(V)"));
    ui->tableWidget_2->setSpan(1,4,2,1);
    ui->tableWidget_2->setItem(1,4,new QTableWidgetItem("校准点(%)"));
    ui->tableWidget_2->setSpan(1,5,1,3);
    ui->tableWidget_2->setItem(1,5,new QTableWidgetItem("有功分量"));
    ui->tableWidget_2->setSpan(1,8,1,3);
    ui->tableWidget_2->setItem(1,8,new QTableWidgetItem("无功分量"));
    ui->tableWidget_2->setItem(2,5,new QTableWidgetItem("标称值(mS)"));
    ui->tableWidget_2->setItem(2,6,new QTableWidgetItem("实际值(mS)"));
    ui->tableWidget_2->setItem(2,7,new QTableWidgetItem("相对误差(%)"));
    ui->tableWidget_2->setItem(2,8,new QTableWidgetItem("标称值(mS)"));
    ui->tableWidget_2->setItem(2,9,new QTableWidgetItem("实际值(mS)"));
    ui->tableWidget_2->setItem(2,10,new QTableWidgetItem("相对误差(%)"));
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 11;j++) {
            QTableWidgetItem *item = ui->tableWidget_2->item(i,j);
            if (item) {
                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));//不可修改
            }
        }
    }
    ui->tableWidget_2->setStyleSheet("QTableWidget::item{border:1px solid ;}");//线条加粗
    int rowline = ui->tableWidget_2->rowCount();//误差数据
    ui->tableWidget_2->setRowCount(rowline + num);
    for (int i = 3;i < num+3;i+=3) {
        ui->tableWidget_2->setSpan(i,0,3,1);
        ui->tableWidget_2->setSpan(i,1,3,1);
        ui->tableWidget_2->setSpan(i,2,3,1);
        ui->tableWidget_2->setSpan(i,3,3,1);
        ui->tableWidget_2->setSpan(i,5,3,1);
        ui->tableWidget_2->setSpan(i,8,3,1);
        QString c = QString::number(i/3);
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(c));

        QTableWidgetItem *item = ui->tableWidget_2->item(i,0);
        //QString c = QString::number(i/3);
        //item->setText(c);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
        item->setFlags(item->flags() & (~Qt::ItemIsEditable));//不可修改
    }
    for (int i = 3;i < num+3;i++) {
        for (int j = 0;j < 11;j++) {
            if (i%3 && (j <= 3 || j == 5 || j == 8)) {
                continue;
            }
            ui->tableWidget_2->setItem(i,j,new QTableWidgetItem("1"));
            if (ui->tableWidget_2->item(i,j)) {
                ui->tableWidget_2->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
                ui->tableWidget_2->item(i,j)->setFlags(ui->tableWidget_2->item(i,j)->flags()&(~Qt::ItemIsEditable));;//不可修改
            }
        }
    }
}
void createtab2::store(Ui::MainWindow *ui) {//保存数据数据
    QSqlQuery query;
    int line = ui->tableWidget_2->rowCount(),number = 0;
    float c1,c5,c8,c6,c7,c9,c10;
    int c3,c4;
    QString c2;
    for (int i = 3;i < line;i+=3) {
        c1 = ui->tableWidget_2->item(i,1)->text().toFloat();
        c2 = ui->tableWidget_2->item(i,2)->text();
        c3 = ui->tableWidget_2->item(i,3)->text().toInt();
        c5 = ui->tableWidget_2->item(i,5)->text().toFloat();
        c8 = ui->tableWidget_2->item(i,8)->text().toFloat();
        for (int j = i;j < i+3;j++) {
            number++;
            c4 = ui->tableWidget_2->item(j,4)->text().toInt();
            c6 = ui->tableWidget_2->item(j,6)->text().toFloat();
            c7 = ui->tableWidget_2->item(j,7)->text().toFloat();
            c9 = ui->tableWidget_2->item(j,9)->text().toFloat();
            c10 = ui->tableWidget_2->item(j,10)->text().toFloat();
            query.prepare("insert into correct(序号,设备编号,标称负荷VA,功率因素,额定电压V,校准点,有功分量标称值mS,有功分量实际值mS,"
                          "`有功分量相对误差%`,无功分量标称值mS,无功分量实际值mS,`无功分量相对误差%`)"
                          "values"
                          "(?,?,?,?,?,?,?,?,?,?,?,?)");
            query.bindValue(0,number);
            query.bindValue(1,id);
            query.bindValue(2,c1);
            query.bindValue(3,c2);
            query.bindValue(4,c3);
            query.bindValue(5,c4);
            query.bindValue(6,c5);
            query.bindValue(7,c6);
            query.bindValue(8,c7);
            query.bindValue(9,c8);
            query.bindValue(10,c9);
            query.bindValue(11,c10);
            query.exec();
        }
    }

}
