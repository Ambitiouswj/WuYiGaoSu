#include "equipment2.h"
#include "ui_equipment2.h"
#include <QDebug>
equipment2::equipment2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipment2)
{
    ui->setupUi(this);
    setWindowTitle(tr("设备管理"));
    ui->lineEdit->setText(pdset.PDbin[N].getNum());
    ui->state->setCurrentIndex(pdset.PDbin[N].getStatus()+1);
    qDebug()<<pdset.PDbin[N].getStatus();
    QString str;
    str=QString::number(pdset.PDbin[N].getAccur(),10,2);
    ui->lineEdit_2->setText(str);
    ui->dateEdit->setDate(pdset.PDbin[N].getDate());
}

void equipment2::on_pushButton_clicked()
{
    pdset.PDbin[N].setNum(ui->lineEdit->text());
    pdset.PDbin[N].setDate(ui->dateEdit->date());
    pdset.PDbin[N].setStatus(ui->state->currentIndex()-1);
    pdset.PDbin[N].setAccur(ui->lineEdit_2->text().toDouble());
    emit senddata(pdset.PDbin[N]);
    this->parentWidget()->show();
    delete this;
}

void equipment2::setLine(QString point)
{
    ui->longit->setText(point);
}

void equipment2::on_pushButton_2_clicked()
{
    this->parentWidget()->show();
    delete this;
}

equipment2::~equipment2()
{
    delete ui;
}
