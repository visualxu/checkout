#include "to_execl.h"

void to_execl::to_exec(Ui::MainWindow *ui)
{
    QList<QPoint> lis;
    QPoint point(100000,12);
    QXlsx::Document xlsx;
    int row = ui->tableWidget_2->rowCount();
    int column = ui->tableWidget_2->columnCount();
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            xlsx.write("A" + QString::number(j+1),ui->tableWidget_2->item(i,j)->text());
        }
    }
    xlsx.saveAs("text.xlsx");
}
