#ifndef EQUIPMENT3_H
#define EQUIPMENT3_H

#include <QDialog>
#include <Main.h>
#include <mainwindow.h>

namespace Ui {
class equipment3;
}

class equipment3 : public QDialog
{
    Q_OBJECT

public:
    explicit equipment3(QWidget *parent = nullptr);
    void setLine(QString point);
    ~equipment3();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void senddata(VideoDevice v);

private:
    Ui::equipment3 *ui;
};

#endif // EQUIPMENT3_H
