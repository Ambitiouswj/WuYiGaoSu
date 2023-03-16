#include "testchart.h"
#include "ui_testchart.h"
#include <QDateTime>
#include <QDebug>
#include "diagram.h"
#include <QMap>
#include <QStandardItem>
Testchart::Testchart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Testchart)
{
    setWindowTitle(tr("车流记录明细"));
    QFile re("pointnum.txt");
    re.open(QIODevice::ReadOnly);
    QByteArray line = re.readLine();
    QString ptnum=line;
    ui->setupUi(this);
    QString filename="D:\\武易高速人车监测系统\\武易高速部分监控数据\\";
    if(ptnum=="K31+950")
        filename+="K31+950-car.xlsx";
    else if(ptnum=="K56+400")
        filename+="K56+400-car.xlsx";
    else if(ptnum=="K96+430")
        filename+="K96+430-car.xlsx";
    //读取Excel表格到tablewidget
    myexcel = new QAxObject("Excel.Application");
    myworks=myexcel->querySubObject("WorkBooks");   //获取工作薄
    myworks->dynamicCall("Open(const QString&)",filename);
    //myworks->dynamicCall("Add"); //添加工作薄
    workbook=myexcel->querySubObject("ActiveWorkBook");
    mysheets=workbook->querySubObject("WorkSheets");    //获取电子表格集
    QAxObject *sheet=workbook->querySubObject("Sheets(int)",1);
    QStringList headname;
    QAxObject *range=sheet->querySubObject("UsedRange");

    QVariant var=range->dynamicCall("Value");
    QList<QList<QVariant>> res;//表格
    QVariantList varRows = var.toList();
    const int rowCount = varRows.size();
    QVariantList rowData;
    for(int i=0;i<rowCount;++i)
    {
        rowData = varRows[i].toList();
        res.push_back(rowData);
    }
     int row_count=res.count();
     int column_count=res.at(0).count();
     for(int i=0;i<res.at(0).count();i++)
     {
         headname<<res.at(0).at(i).toString();
     }
     ui->tableWidget->setColumnCount(column_count);
     ui->tableWidget->setRowCount(row_count-2);
    //设置表头
    QTableWidgetItem *headerItem;
    for (int i=0;i<ui->tableWidget->columnCount();i++)//列编号从0开始
    {
      ui->tableWidget->setColumnWidth(i,150);
      headerItem=new QTableWidgetItem(headname.at(i)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
      QFont font=headerItem->font();//获取原有字体设置
      font.setPointSize(10);//字体大小
      headerItem->setTextColor(Qt::red);//字体颜色
      headerItem->setFont(font);//设置字体
      ui->tableWidget->setHorizontalHeaderItem(i,headerItem); //设置表头单元格的Item
     }
    //QString str;
    QTableWidgetItem *item;
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setAlternatingRowColors(true);
    QDateTime m_start=QDateTime::fromString(res.at(2).at(1).toString(),"yyyy-MM-dd hh:mm:ss");
    QDateTime m_end=QDateTime::fromString(res.at(row_count-1).at(1).toString(),"yyyy-MM-dd hh:mm:ss");
    for(int i=2;i<row_count;i++)
    {
       QDateTime t= QDateTime::fromString((res.at(i).at(1)).toString(),"yyyy-MM-dd hh:mm:ss");
        for(int j=0;j<column_count;j++)
        {
            item=new QTableWidgetItem(res.at(i).at(j).toString());
            item->setFlags(Qt::ItemIsEnabled);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(i-2,j,item);
        }
    }
    ui->tableWidget->horizontalHeaderItem(3)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\车速表.png"));
    ui->tableWidget->horizontalHeaderItem(1)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\时间.png"));
    ui->tableWidget->horizontalHeaderItem(0)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\视频监控.png"));
    ui->tableWidget->horizontalHeaderItem(2)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\路桩.png"));
    ui->tableWidget->horizontalHeaderItem(4)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\车牌.png"));
    ui->pushButton_2->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\数据.png"));
    ui->pushButton_2->setFlat(true);
    ui->pushButton_2->setIconSize(QSize(30,30));

}

Testchart::~Testchart()
{
    delete ui;
}


void Testchart::on_pushButton_2_clicked()
{
    diagram *a=new diagram();
    a->show();
}

