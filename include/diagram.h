#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QWidget>
#include <QAxObject>
namespace Ui {
class diagram;
}

class diagram : public QWidget
{
    Q_OBJECT

public:
    explicit diagram(QWidget *parent = nullptr);
    ~diagram();
    void initExcel();
    void initUI();
    void initData();
    void initConnect();
    void widget_car();
public slots:

    void clickedItem(QPieSlice *slice);

private:
    QAxObject *myexcel;     //Excel 应用程序指针
    QAxObject *myworks;     //工作薄集指针
    QAxObject *workbook;   //工作薄指针
    QAxObject *mysheets;    //电子表格指针
    int Rowcount;
    int Rowcount1;
    int row;
    int col;

    QMap<QString,double> place;
    QPieSeries *series;
    QChart *chart;
    QChartView *chartview;
    Ui::diagram *ui;
};

#endif // DIAGRAM_H
