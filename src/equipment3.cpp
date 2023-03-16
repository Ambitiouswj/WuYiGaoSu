#include "equipment3.h"
#include "ui_equipment3.h"

equipment3::equipment3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipment3)
{
    ui->setupUi(this);
    setWindowTitle(tr("设备管理"));
    ui->lineEdit->setText(vdset.VDbin[N].getNum());
    ui->state->setCurrentIndex(vdset.VDbin[N].getStatus());
    QString str;
    str=QString::number(vdset.VDbin[N].getRatio());
    ui->lineEdit_2->setText(str);
    ui->dateEdit->setDate(vdset.VDbin[N].getDate());
}

void equipment3::on_pushButton_clicked()
{
    vdset.VDbin[N].setNum(ui->lineEdit->text());
    vdset.VDbin[N].setDate(ui->dateEdit->date());
    vdset.VDbin[N].setStatus(ui->state->currentIndex());
    vdset.VDbin[N].setRatio(ui->lineEdit_2->text().toInt());
    emit senddata(vdset.VDbin[N]);
    this->parentWidget()->show();
    delete this;
}

void equipment3::setLine(QString point)
{
    ui->longit->setText(point);
}

void equipment3::on_pushButton_2_clicked()
{
    this->parentWidget()->show();
    delete this;
}

equipment3::~equipment3()
{
    delete ui;
}
