#ifndef POINTSHOW_H
#define POINTSHOW_H

#include <QWidget>
#include "Main.h"

namespace Ui {
class PointShow;
}

class PointShow : public QWidget
{
    Q_OBJECT

public:
    explicit PointShow(QWidget *parent = nullptr);
    ~PointShow();

    void show();

    void show1();

    void show2();

private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::PointShow *ui;
};

#endif // POINTSHOW_H
