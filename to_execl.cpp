#include "to_execl.h"
#include<QPixelFormat>
void to_execl::to_exec(Ui::MainWindow *ui)
{
    QXlsx::Document xlsx;
    QXlsx::Format format;
    format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    format.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    int row = ui->tableWidget_2->rowCount();
    int column = ui->tableWidget_2->columnCount();
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            if (ui->tableWidget_2->item(i,j)) {
                xlsx.write('A' + j + QString::number(i+1),ui->tableWidget_2->item(i,j)->text(),format);

            }
        }
    }
    xlsx.mergeCells("A1:K1",format);//合并第一行第A~K列
    xlsx.mergeCells("A2:A3",format);
    xlsx.mergeCells("B2:B3",format);
    xlsx.mergeCells("C2:C3",format);
    xlsx.mergeCells("D2:D3",format);
    xlsx.mergeCells("E2:E3",format);
    xlsx.mergeCells("F2:H2",format);
    xlsx.mergeCells("I2:K2",format);
    for (int i = 3;i < row;i+=3) {
        xlsx.mergeCells("A" + QString::number(i+1) + ":" + "A" + QString::number(i+3),format);
        xlsx.mergeCells("B" + QString::number(i+1) + ":" + "B" + QString::number(i+3),format);
        xlsx.mergeCells("C" + QString::number(i+1) + ":" + "C" + QString::number(i+3),format);
        xlsx.mergeCells("D" + QString::number(i+1) + ":" + "D" + QString::number(i+3),format);
        xlsx.mergeCells("F" + QString::number(i+1) + ":" + "F" + QString::number(i+3),format);
        xlsx.mergeCells("I" + QString::number(i+1) + ":" + "I" + QString::number(i+3),format);
    }
    xlsx.saveAs("text.xlsx");
}
