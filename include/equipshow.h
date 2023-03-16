#ifndef EQUIPSHOW_H
#define EQUIPSHOW_H

#include <QWidget>
#include "Main.h"

namespace Ui {
class EquipShow;
}

class EquipShow : public QWidget
{
    Q_OBJECT

public:
    explicit EquipShow(QWidget *parent = nullptr);
    ~EquipShow();
    void allShow();
    void show1();
    void show2();
    void show3();
private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::EquipShow *ui;
};

#endif // EQUIPSHOW_H
