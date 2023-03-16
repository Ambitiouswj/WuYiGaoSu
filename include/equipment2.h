#ifndef EQUIPMENT2_H
#define EQUIPMENT2_H

#include <QDialog>
#include <Main.h>
#include <mainwindow.h>

namespace Ui {
class equipment2;
}

class equipment2 : public QDialog
{
    Q_OBJECT

public:
    explicit equipment2(QWidget *parent = nullptr);
    void setLine(QString point);
    ~equipment2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void senddata(PersonDevice p);

private:
    Ui::equipment2 *ui;
};

#endif // EQUIPMENT2_H
