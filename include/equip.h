#ifndef EQUIP_H
#define EQUIP_H
#include "Main.h"
#include "equipment.h"
#include <QWidget>
#include <QString>

namespace Ui {
class Equip;
}

class Equip : public QWidget
{
    Q_OBJECT

public:
    explicit Equip(QWidget *parent = nullptr);
    ~Equip();

//public:
//    Device Getformation();

      void setLabel(QString point,QString zuobiao1,QString zuobiao2,QString location);


private slots:



      void on_pushButton_5_clicked();

      void on_pushButton_clicked();

      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();

private:
    void GetDate(CarDevice c);
    void GetpDate(PersonDevice p);
    void GetvDate(VideoDevice v);

private:
    Ui::Equip *ui;
//    Device car;

//signals:
//    void senddata();
};

#endif // EQUIP_H
