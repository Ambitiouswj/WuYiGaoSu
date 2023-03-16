#include "widget.h"
#include "widget2.h"
#include "Main.h"
#include "addpoint.h"
#include "equipshow.h"
QVector<QToolButton*> Btn;
int count1=3;
Widget::Widget():
    Paint(10,10,1175,590),
    Alloffset(0,0),
    label("100%",this),
    EquipButton(this),
    LiftButton(this),
    RightButton(this),
    UpButton(this),
    DownButton(this),
    ResetButton(this)
{
    ratio= 1.0;             //始化图片缩放比例
    action = Widget::None;
    setWindowTitle(tr("武易高速人车监测数据展示系统"));

    EquipButton.setGeometry(445,630,50,50);
    EquipButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测设备.png"));
    EquipButton.setIconSize(QSize(50,50));
    EquipButton.setFlat(true);
    connect(&EquipButton,SIGNAL(clicked()),this,SLOT(onEquipClicked()));

    LiftButton.setGeometry(140,630,50,50);
    LiftButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\左.png"));
    LiftButton.setIconSize(QSize(50,50));
    LiftButton.setFlat(true);
    connect(&LiftButton,SIGNAL(clicked()),this,SLOT(OnLiftClicked()));

    RightButton.setGeometry(200,630,50,50);
    RightButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\右.png"));
    RightButton.setIconSize(QSize(50,50));
    RightButton.setFlat(true);
    connect(&RightButton,SIGNAL(clicked()),this,SLOT(OnRightClicked()));

    UpButton.setGeometry(260,630,50,50);
    UpButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\上.png"));
    UpButton.setIconSize(QSize(50,50));
    UpButton.setFlat(true);
    connect(&UpButton,SIGNAL(clicked()),this,SLOT(onUpClicked()));

    DownButton.setGeometry(320,630,50,50);
    DownButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\下.png"));
    DownButton.setIconSize(QSize(50,50));
    DownButton.setFlat(true);
    connect(&DownButton,SIGNAL(clicked()),this,SLOT(onDownClicked()));

    ResetButton.setGeometry(380,630,50,50);
    ResetButton.setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\还原.png"));
    ResetButton.setIconSize(QSize(50,50));
    ResetButton.setFlat(true);
    connect(&ResetButton,SIGNAL(clicked()),this,SLOT(onResetClicked()));

    QString str ="D:\\武易高速人车监测系统\\ICON\\333.png" ;
    if(!str.isNull())
    {
       image.load(str);
       pix = pix.fromImage(image);
       crtPix = pix;
       pixW = image.width();            //图片宽
       pixH = image.height();           //图片高
       qDebug()<<str<<pixW<<pixH;
       this->setWindowTitle("图片浏览器("+str+")");
       action=Widget::Reset;
       Alloffset.setX(0);
       Alloffset.setY(0);
       ratio = 1.000;
       label.setText("100%");
       this->update();
    }
    initPoint();
    label.move(1040,660);
    label.setVisible(false);
    resize(1200,700);
    this->setWindowTitle("武易高速人车监测数据展示系统");
}

bool Widget::event(QEvent * event)
{
    static bool press=false; //判断是否点击
    static QPoint PreDot;

    if(event->type() == QEvent::MouseButtonPress )
    {
           QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
           if(mouse->button() == Qt::RightButton)
           {
               //新建监测点按钮
               QToolButton *btn=new QToolButton(this);
               Btn.push_back(btn);//将新建的按钮存在vector容器中  方便后续操作
               loca.insert(btn,QPair<int,int>(mouse->pos().x(),mouse->pos().y()));//
               count1++;//记录监测点的数目

               btn->setVisible(true);
               btn->move(mouse->pos().x(),mouse->pos().y());//将监测点按钮移动至鼠标右击的位置
               btn->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));//设置icon图标
               btn->setIconSize(QSize(30,30));//设置icon图标大小
               btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//设置图标和文字的位置风格
               btn->setStyleSheet("QToolButton{background-color:rgba(0,0,0,0);}");
               //新建菜单
               QMenu *menu = new QMenu();
               QAction *act1 = new QAction();
               QAction *act2 = new QAction();
               QAction *act3 = new QAction();

               act1->setText("具体信息");
               act2->setText("添加监测点");
               act3->setText("停用监测点");

               act1->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\信息 (2).png"));
               act2->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\添加.png"));
               act3->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\操作-开关.png"));

               menu->addAction(act1);
               menu->addAction(act2);
               menu->addAction(act3);

               btn->setPopupMode(QToolButton::InstantPopup);
               btn->setMenu(menu);
               //连接槽函数
               connect(act1,SIGNAL(triggered(bool)),this,SLOT(menuAct1ClickedSlots()));
               connect(act2,SIGNAL(triggered(bool)),this,SLOT(menuAct2ClickedSlots()));
               connect(act3,SIGNAL(triggered(bool)),this,SLOT(menuAct3ClickedSlots()));
           }

           //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
           if(mouse->button()==Qt::LeftButton &&Paint.contains(mouse->pos()))
           {
               press=true;
               QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
               PreDot = mouse->pos();
           }
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        //判断鼠标是否是左键释放,且之前是在绘画区域
        if(mouse->button()==Qt::LeftButton && press )   //左键点击
        {
            QApplication::setOverrideCursor(Qt::ArrowCursor); //改回鼠标样式
            press=false;
        }
    }
     if(event->type() == QEvent::MouseMove)              //移动图片
     {
          if(press)
         {
            QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

            offset.setX(mouse->x() - PreDot.x());
            offset.setY(mouse->y() - PreDot.y());
            PreDot = mouse->pos();
            action = Widget::Move;
            this->update();
         }
     }
    return QWidget::event(event);
}

void Widget::wheelEvent(QWheelEvent* event)     //鼠标滑轮事件
{
 if (event->delta()>0)
 {      //上滑,缩小
    action=Widget::Shrink;
    this->update();
 }
 else
 {                    //下滑,放大
     action=Widget::Amplification;
     this->update();
 }

 event->accept();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform|QPainter::Antialiasing|QPainter::TextAntialiasing);
    painter.drawRect(Paint.x()-1,Paint.y()-1,Paint.width()+1,Paint.height()+1); //画框

    if(image.isNull())
    {
     return;
    }

    int NowW = ratio *pixW;
    int NowH = ratio *pixH;

    if(action==Widget::Shrink)           //缩小
    {
          ratio-=0.05*ratio;
        if(ratio<0.018)
          ratio = 0.01;

        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",ratio*100);
        label.setText(str) ;
        qDebug()<<"缩小:"<<ratio;
    }
    else  if(action==Widget::Amplification)           //放大
    {

         ratio+=0.05*ratio;
       if(ratio>4.5)
         ratio = 5.000;

        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",ratio*100);
        label.setText(str);
        qDebug()<<"放大:"<<ratio;
    }


    if(action==Widget::Amplification || action==Widget::Shrink || action==Widget::Reset)      //更新图片
    {
      NowW = ratio *pixW;
      NowH = ratio *pixH;
      crtPix= pix.scaled(NowW, NowH,Qt::KeepAspectRatio,Qt::SmoothTransformation); //重新装载
      action=Widget::None;
    }
    if(action==Widget::Move)                    //移动
    {
        int offsetx=Alloffset.x()+offset.x();
        Alloffset.setX(offsetx);

        int offsety=Alloffset.y()+offset.y();
        Alloffset.setY(offsety);
        action=Widget::None;
    }

    if(abs(Alloffset.x())>=(Paint.width()/2 + NowW/2 -10))    //限制X偏移值
    {
        if(Alloffset.x()>0)
            Alloffset.setX(Paint.width()/2 + NowW/2 -10);
        else
         Alloffset.setX(-Paint.width()/2 + -NowW/2 +10);

    }
    if(abs(Alloffset.y())>=(Paint.height()/2 + NowH/2 -10))    //限制Y偏移值
    {
        if(Alloffset.y()>0)
            Alloffset.setY(Paint.height()/2 + NowH/2 -10);
        else
         Alloffset.setY(-Paint.height()/2 + -NowH/2 +10);

    }

    int x = Paint.width()/2 + Alloffset.x() -NowW/2;
    if(x<0)
        x=0;

    int y = Paint.height()/2 + Alloffset.y() -NowH/2;
    if(y<0)
        y=0;

    int  sx = NowW/2 - Paint.width()/2 - Alloffset.x();
    if(sx<0)
        sx=0;

    int  sy = NowH/2 - Paint.height()/2 - Alloffset.y();
    if(sy<0)
        sy=0;

    int w =(NowW - sx)>Paint.width()? Paint.width() : (NowW - sx);
    if(w>(Paint.width()-x))
        w = Paint.width()-x;

    int h =(NowH - sy)>Paint.height()? Paint.height() : (NowH - sy);
    if(h>(Paint.height()-y))
        h = Paint.height()-y;

    painter.drawTiledPixmap(x+Paint.x(),y+Paint.y(),w,h,crtPix,sx,sy);             //绘画图形
}

void Widget::onEquipClicked()
{
    EquipShow *e=new EquipShow();
    e->show();
}
//向上移动
void Widget::onUpClicked()
{
  action=Widget::Move;
  offset.setX(0);
  offset.setY(-20);
      for(int i=0;i<count1;i++)
      {
           int k=Btn[i]->x();
           int k1=Btn[i]->y();
           Btn[i]->move(k,k1-20);
      }

  this->update();
}
//向下移动
void Widget::onDownClicked()
{
  action=Widget::Move;
  offset.setX(0);
  offset.setY(20);
      for(int i=0;i<count1;i++)
      {
           int k=Btn[i]->x();
           int k1=Btn[i]->y();
           Btn[i]->move(k,k1+20);
      }

  this->update();
}
//还原按钮的实现
void Widget::onResetClicked()
{
  action=Widget::Reset;
  Alloffset.setX(0);
  Alloffset.setY(0);
  for(int i=0;i<count1;i++)
  {
     int poty=loca[Btn[i]].QPair::second;
     int potx=loca[Btn[i]].QPair::first;
      Btn[i]->move(potx,poty);
  }
  ratio = 1.000;
  label.setText("100%");
  this->update();
}
//向左移动
void Widget::OnLiftClicked()
{
  action=Widget::Move;
  offset.setX(-20);
  offset.setY(0);
  for(int i=0;i<count1;i++)
  {
       int k=Btn[i]->x();
       int k1=Btn[i]->y();
       Btn[i]->move(k-20,k1);
  }
  this->update();
}
//向右移动
void Widget::OnRightClicked()
{
    action=Widget::Move;
    offset.setX(20) ;
    offset.setY(0) ;
    for(int i=0;i<count1;i++)
    {
        int k=Btn[i]->x();
        int k1=Btn[i]->y();
        Btn[i]->move(k+20,k1);
    }
    this->update();
}

void write(QString pnum)
{
    QFile wt("pointnum.txt");
    wt.open(QIODevice::WriteOnly|QIODevice::Text);
    wt.write(QString(pnum).toUtf8());
    wt.close();
}

//监测点具体信息
void Widget::menuAct1ClickedSlots()
{

    if(mp1.PointBin.size() < count1)
    {
        QMessageBox::critical(0 , "警告" , "该点信息未进行初始化", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
    }
    else
    {
        write("K61+150");
        Widget2 *w1=new Widget2();
        w1->show();
    }
}
void Widget::menuAct1ClickedSlots1()
{

    write("K56+400");
    Widget2 *w1=new Widget2();
    w1->show();
}
void Widget::menuAct1ClickedSlots2()
{

    write("K96+430");
    Widget2 *w1=new Widget2();
    w1->show();
}
void Widget::menuAct1ClickedSlots3()
{

    write("K31+950");
    Widget2 *w1=new Widget2();
    w1->show();
}
//添加监测点
void Widget::menuAct2ClickedSlots()
{
    AddPoint *ad1=new AddPoint();
    ad1->show();
}

//运行/停用
void Widget::menuAct3ClickedSlots()
{
    if(mp1.PointBin.size() < count1)
    {
        QMessageBox::critical(0 , "警告" , "该点信息未进行初始化", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
    }
    else if(mp1.PointBin[count1-1].getStatus()==working)
    {
        Btn[count1-1]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
        Btn[count1-1]->setIconSize(QSize(30,30));
        mp1.PointBin[count1-1].setStatus(2);
    }
    else
    {
        Btn[count1-1]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点1.png"));
        Btn[count1-1]->setIconSize(QSize(30,30));
        mp1.PointBin[count1-1].setStatus(0);
    }
}
void Widget::menuAct3ClickedSlots1()
{
    if(mp1.PointBin[0].getStatus()==working)
    {
        Btn[0]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点1.png"));
        Btn[0]->setIconSize(QSize(30,30));
        mp1.PointBin[0].setStatus(2);
    }
    else
    {
        Btn[0]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
        Btn[0]->setIconSize(QSize(30,30));
        mp1.PointBin[0].setStatus(0);
    }
}
void Widget::menuAct3ClickedSlots2()
{

    if(mp1.PointBin[1].getStatus()==working)
    {
        Btn[1]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点1.png"));
        Btn[1]->setIconSize(QSize(30,30));
        mp1.PointBin[1].setStatus(2);
    }
    else
    {
        Btn[1]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
        Btn[1]->setIconSize(QSize(30,30));
        mp1.PointBin[1].setStatus(0);
    }
}
void Widget::menuAct3ClickedSlots3()
{
    if(mp1.PointBin[2].getStatus()==working)
    {
        Btn[2]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点1.png"));
        Btn[2]->setIconSize(QSize(30,30));
        mp1.PointBin[2].setStatus(2);
    }
    else
    {
        Btn[2]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
        Btn[2]->setIconSize(QSize(30,30));
        mp1.PointBin[2].setStatus(0);
    }
}


void Widget::initPoint()
{
    Qinglong->setGeometry(296,320,80,50);
    Qinglong->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
    Qinglong->setIconSize(QSize(30,30));
    Qinglong->setText(QString("青龙立交"));
    Qinglong->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Qinglong->setStyleSheet("QToolButton{background-color:rgba(0,0,0,0);}");

    Yimeng->setGeometry(59,290,80,50);
    Yimeng->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
    Yimeng->setIconSize(QSize(30,30));
    Yimeng->setText(QString("易门服务站"));
    Yimeng->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Yimeng->setStyleSheet("QToolButton{background-color:rgba(0,0,0,0);}");

    Qianyin->setGeometry(187,310,80,50);
    Qianyin->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
    Qianyin->setIconSize(QSize(30,30));
    Qianyin->setText(QString("前营立交"));
    Qianyin->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Qianyin->setStyleSheet("QToolButton{background-color:rgba(0,0,0,0);}");

    Btn.push_back(Qinglong);
    Btn.push_back(Yimeng);
    Btn.push_back(Qianyin);

    loca.insert(Qinglong,QPair<int,int>(296,320));
    loca.insert(Yimeng,QPair<int,int>(59,290));
    loca.insert(Qianyin,QPair<int,int>(187,310));
    QMenu *menu1 = new QMenu();
    QMenu *menu2 = new QMenu();
    QMenu *menu3 = new QMenu();
    QAction *act1_1 = new QAction();
    QAction *act3_1 = new QAction();
    QAction *act1_2 = new QAction();
    QAction *act3_2 = new QAction();
    QAction *act1_3 = new QAction();
    QAction *act3_3 = new QAction();

    act1_1->setText("具体信息");
    act3_1->setText("运行/停用");
    act1_2->setText("具体信息");
    act3_2->setText("运行/停用");
    act1_3->setText("具体信息");
    act3_3->setText("运行/停用");

    act1_1->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\信息 (2).png"));
    act1_2->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\信息 (2).png"));
    act1_3->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\信息 (2).png"));

    act3_1->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\操作-开关.png"));
    act3_2->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\操作-开关.png"));
    act3_3->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\操作-开关.png"));

    //6.将action加入菜单中
    menu1->addAction(act1_1);
    menu1->addAction(act3_1);
    menu2->addAction(act1_2);
    menu2->addAction(act3_2);
    menu3->addAction(act1_3);
    menu3->addAction(act3_3);

    //7.将对象menu设置成menu的菜单
     Qinglong->setPopupMode(QToolButton::InstantPopup);
     Qinglong->setMenu(menu1);
     Yimeng->setPopupMode(QToolButton::InstantPopup);
     Yimeng->setMenu(menu2);
     Qianyin->setPopupMode(QToolButton::InstantPopup);
     Qianyin->setMenu(menu3);

     //8.每个action的触发信号关联相对应的槽函数
     connect(act1_1,SIGNAL(triggered(bool)),this,SLOT(menuAct1ClickedSlots1()));
     connect(act3_1,SIGNAL(triggered(bool)),this,SLOT(menuAct3ClickedSlots1()));
     connect(act1_2,SIGNAL(triggered(bool)),this,SLOT(menuAct1ClickedSlots2()));
     connect(act3_2,SIGNAL(triggered(bool)),this,SLOT(menuAct3ClickedSlots2()));
     connect(act1_3,SIGNAL(triggered(bool)),this,SLOT(menuAct1ClickedSlots3()));
     connect(act3_3,SIGNAL(triggered(bool)),this,SLOT(menuAct3ClickedSlots3()));

}
void Widget::initpoint1()
{
    for(int i=0;i<mp1.PointBin.size();i++)
    {
        if(mp1.PointBin[i].getStatus()==working)
        {
            Btn[i]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点.png"));
            mp1.PointBin[i].setStatus(3);
        }
        else
        {
            Btn[i]->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\监测点1.png"));
            mp1.PointBin[i].setStatus(0);
        }
    }
}
