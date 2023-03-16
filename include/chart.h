#ifndef CHART_H
#define CHART_H

#include "Main.h"
QT_CHARTS_USE_NAMESPACE


namespace Ui {class Chart;}

class Chart : public QWidget
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = nullptr);
    ~Chart();

    void drawCarChart();

    void drawPersonChart();

    QSplineSeries *mSeries = new QSplineSeries();
    //QSplineSeries *mSeries2 = new QSplineSeries();
    QDateTime curDateTIme = QDateTime::currentDateTime();

    QChartView *chartView;

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_5_clicked();

private:
    Ui::Chart *ui;
};

#endif // CHART_H
