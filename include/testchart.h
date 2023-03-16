#ifndef TESTCHART_H
#define TESTCHART_H

#include <QMainWindow>
#include <QAxObject>
#include "Main.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Testchart; }
QT_END_NAMESPACE

class Testchart : public QMainWindow
{
    Q_OBJECT

public:
    explicit Testchart(QWidget *parent = nullptr);
    ~Testchart();
private slots:

    void on_pushButton_2_clicked();


private:
    QAxObject *myexcel;     //Excel 搴旂敤绋嬪簭鎸囬拡
    QAxObject *myworks;     //宸ヤ綔钖勯泦鎸囬拡
    QAxObject *workbook;   //宸ヤ綔钖勬寚閽
    QAxObject *mysheets;    //鐢靛瓙琛ㄦ牸鎸囬拡
    Ui::Testchart *ui;
};
#endif // TESTCHART_H
