#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include "Main.h"
namespace Ui {
class Widget1;
}

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget1(QWidget *parent = nullptr);
    ~Widget1();
    void CarShow(QVector<CarRecord> &obj,QDateTime begin,QDateTime end);
    void PersonShow(QVector<PersonRecord> &obj,QDateTime begin,QDateTime end);

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_chart_clicked();

    void on_data_clicked();

    void on_video_clicked();

    void on_equip_clicked();

    void on_reset_2_clicked();

    void on_toback_clicked();

private:
    Ui::Widget1 *ui;
};

#endif // WIDGET1_H
