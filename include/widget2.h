#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "Main.h"

namespace Ui {
class Widget2;
}

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = nullptr);
    ~Widget2();

    void CarShow(QVector<CarRecord> &obj,QDateTime begin,QDateTime end);

    void PersonShow(QVector<PersonRecord> &obj,QDateTime begin,QDateTime end);
private slots:
    void on_pushButton_5_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_chart_clicked();

    void on_data_clicked();

    void on_video_clicked();

    void on_equip_clicked();

    void on_reset_clicked();

private:
    Ui::Widget2 *ui;
};

#endif // WIDGET2_H
