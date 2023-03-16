#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QDialog>
#include <Main.h>
#include <mainwindow.h>

namespace Ui {
class equipment;
}

class equipment : public QDialog
{
    Q_OBJECT

public:
    explicit equipment(QWidget *parent = nullptr);
    void setLine(QString point);
    ~equipment();
signals:
    void senddata(CarDevice c);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::equipment *ui;
};

#endif // EQUIPMENT_H
