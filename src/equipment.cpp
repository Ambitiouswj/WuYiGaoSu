#include "equipment.h"
#include "ui_equipment.h"
#include "equip.h"
#include <QDebug>
#include "Main.h"

equipment::equipment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipment)
{
    ui->setupUi(this);
    setWindowTitle(tr("设备管理"));
    ui->lineEdit->setText(cdset.CDbin[N].getNum());
    ui->state->setCurrentIndex(cdset.CDbin[N].getStatus()+1);
    QString str;
    str=QString::number(cdset.CDbin[N].getAccur(),10,2);
    ui->lineEdit_2->setText(str);
    ui->dateEdit->setDate(cdset.CDbin[N].getDate());
}

equipment::~equipment()
{
    delete ui;
}

void equipment::on_pushButton_clicked()
{
    cdset.CDbin[N].setNum(ui->lineEdit->text());
    cdset.CDbin[N].setDate(ui->dateEdit->date());
    cdset.CDbin[N].setStatus(ui->state->currentIndex()-1);
    cdset.CDbin[N].setAccur(ui->lineEdit_2->text().toDouble());
    emit senddata(cdset.CDbin[N]);
    this->parentWidget()->show();
    delete this;
}

void equipment::setLine(QString point)
{
    ui->longit->setText(point);
}

void equipment::on_pushButton_2_clicked()
{
    this->parentWidget()->show();
    delete this;
   // this->close();
}

