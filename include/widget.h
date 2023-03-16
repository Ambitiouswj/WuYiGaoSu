#ifndef WIDGET_H
#define WIDGET_H
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QApplication>
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QPair>
#include <QFrame>
#include <QToolButton>
#include <QMap>
#include "widget1.h"
#include "addpoint.h"
namespace Ui {
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT

private :
    Ui::Widget *ui;
    QString pointnum;
    QMap<QToolButton*,QPair<int,int>> loca;
    QPixmap  pix;
    QPixmap  crtPix;
    int action;          //动作(放大,缩小,移动)
    int pixW;            //图片宽
    int pixH;            //图片高
    QRect Paint;         //绘画区域
    QImage image;        //打开的图片
    float ratio;         //缩放比例
    QPoint offset;       //一次的图片偏移值
    QPoint Alloffset;    //图片总偏移
    QLabel label;
    QPushButton  EquipButton;
    QPushButton  LiftButton;
    QPushButton  RightButton;
    QPushButton  UpButton;
    QPushButton  DownButton;
    QPushButton  ResetButton;

    QToolButton  *Qinglong=new QToolButton(this);
    QToolButton  *Yimeng=new QToolButton(this);
    QToolButton  *Qianyin=new QToolButton(this);

    void AddComboItem(QComboBox* cmbo);
    bool event(QEvent * event);
    void wheelEvent(QWheelEvent* e);     //鼠标滑轮事件
private slots:
    void onEquipClicked();
    void onUpClicked(); //上移Button
    void onDownClicked();//下移Button
    void onResetClicked();//还原Button  实现将图片以及按钮恢复为原大小以及原位置
    void OnLiftClicked();//左移Button
    void OnRightClicked();//右移Button
    void paintEvent(QPaintEvent *event);
    void menuAct1ClickedSlots();//
    void menuAct2ClickedSlots();
    void menuAct3ClickedSlots();
    void menuAct1ClickedSlots1();
    void menuAct1ClickedSlots2();
    void menuAct1ClickedSlots3();
    void menuAct3ClickedSlots1();
    void menuAct3ClickedSlots2();
    void menuAct3ClickedSlots3();
    void initPoint();//初始化各Button的参数
    void initpoint1();
public:
    explicit Widget();
    friend class Widget1;
    enum Type
    {
        None = 0,
        Amplification ,
        Shrink,
        Lift,
        Right,
        Up,
        Down,
        Move,
        Reset
    };

};
#endif // WIDGET_H
