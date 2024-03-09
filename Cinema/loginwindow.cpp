#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

loginwindow::loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);
}





void loginwindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    for (int i = 0; i< usersCount; ++i)
    {
        if(usernames[i] == username && passwords[i] == password)
        {
            hide();
            WelcomeWindow* welcomeWindow = new WelcomeWindow(username, getuserAge(username), this);
            welcomeWindow->show();
        }

    }
    ui->labelError->setVisible(true);
}


void loginwindow::on_pushButtonRegister_clicked()
{
    hide();
    registerwindow* Registerwindow = new registerwindow(this);
    Registerwindow->show();
}

loginwindow::~loginwindow()
{
    delete ui;
}

