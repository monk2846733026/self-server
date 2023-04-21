#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTime>

void Widget::tablepayshow()
{
    QList<Pay> a = m_sql->getallpay(BASEINFO,user_id+"pay");
    int size = a.size();
    qDebug()<<"size of pay:"<<size;
    int allpay=0;
    ui->tableWidget->setRowCount(size);
    for(int index=0;index<size;index++)
    {
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(a[index].project));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(a[index].size)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(a[index].unit));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(a[index].total));
        allpay+=a[index].total.toInt();
    }

    ui->label_18->setText(QString("%1rmb").arg(QString::number(allpay)));


    //获取表格行数
    int rowNum = ui->tableWidget->rowCount();
    //打印表格的标题
    QString title = QString("缴费明细清单");
    //columnList为各列名
    QStringList columnList;
    //dataLists为各行数据
    QVector<QStringList> dataLists;
    columnList<<"1"<<"2"<<"3"<<"4";

    //表格内存储到dataLists
    QString text = "";
    for(int i=0;i<1;i++)
    {
        QStringList data;
        for(int j=0;j<4;j++)
        {
            QTableWidgetItem* items = ui->tableWidget->item(i,j);
            text = items->text();
            data << text;
        }
        dataLists.push_back(data);
    }

    //声明打印（内容）QPrinterManager类，并调用其函数
    QPrinterManager PM;
    PM.dataBegin();
    PM.insertTitle(title);
//    PM.insertTitle2(tr("次级标题"));
    PM.tableBegin(columnList);
    for(int row=0;row<rowNum;row++)
    {
        PM.insert2TableRow(dataLists[row]);
    }

    PM.tableEnd();
    PM.dataEnd();
    PM.printWithPreview();


}
