#ifndef ADDPOINT_H
#define ADDPOINT_H

#include <QDialog>
#include "Main.h"
namespace Ui {
class AddPoint;
}

class AddPoint : public QDialog
{
    Q_OBJECT

public:
    explicit AddPoint(QWidget *parent = nullptr);
    ~AddPoint();

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::AddPoint *ui;
};

#endif // ADDPOINT_H
