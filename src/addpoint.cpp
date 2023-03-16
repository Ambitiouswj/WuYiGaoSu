#include "addpoint.h"
#include "ui_addpoint.h"
AddPoint::AddPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPoint)
{
    ui->setupUi(this);
    setWindowTitle(tr("添加监测点"));
}

AddPoint::~AddPoint()
{
    delete ui;
}

void AddPoint::on_ok_clicked()
{
        Coord newcoord;
        SenPoint p1;
        newcoord.setWE(ui->comboBox->currentIndex());
        newcoord.setNS(ui->comboBox_2->currentIndex());
        newcoord.setLatit(ui->lineEdit_4->text().toDouble());
        newcoord.setLongit(ui->lineEdit_3->text().toDouble());
        SenPoint newpoint;
        newpoint.setNum(ui->lineEdit_2->text());
        newpoint.setLocate(ui->lineEdit->text());
        newpoint.setCoord(newcoord);
        mp1.addPoint(newpoint);
        qDebug()<<"123";
        qDebug()<<Btn.size();
        QString str=ui->lineEdit->text();
        Btn[count1-1]->setText(str);
        Btn[count1-1]->resize(80,50);
        p1.setCoord(newcoord);
        p1.setLocate(ui->lineEdit->text());
        p1.setNum(ui->lineEdit_2->text());
        p1.setStatus(0);
        mp1.PointBin.push_back(p1);
        this->close();
}


void AddPoint::on_cancel_clicked()
{
    this->close();
}

