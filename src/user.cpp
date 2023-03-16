#include "user.h"
#include "ui_user.h"
#include "widget.h"
UserInFo::UserInFo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInFo)
{
    ui->setupUi(this);
    setWindowTitle(tr("用户登录"));
}

UserInFo::~UserInFo()
{
    delete ui;
}

void UserInFo::on_Back_clicked()
{
    this->close();
}


void UserInFo::on_LogIn_clicked()
{
    ui->username->setText("wuyigaosu@cqjtu.com");
    ui->password->setText("123456");
    QString useName=ui->username->text();
    QString passWord=ui->password->text();
    if(useName=="wuyigaosu@cqjtu.com" && passWord=="123456")
    {
        Widget *m1=new Widget();
        m1->show();
        this->hide();
    }
    else
    {
        int r=QMessageBox::warning(this,tr("错误"),tr("您输入的用户名或密码错误"),QMessageBox::Abort);
        //if(r==QMessageBox::Abort) qDebug()<<tr("警告")；

    }
}

