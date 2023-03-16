#ifndef USER_H
#define USER_H

#include <QWidget>
#include "Main.h"
namespace Ui {
class UserInFo;
}

class UserInFo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInFo(QWidget *parent = nullptr);
    ~UserInFo();

private slots:
    void on_Back_clicked();

    void on_LogIn_clicked();

private:
    Ui::UserInFo *ui;
};

#endif // USER_H
