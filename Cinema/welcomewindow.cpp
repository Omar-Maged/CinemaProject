#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(const QString& username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    ui->labelHello->setText("Hello " + username + " " + QString::number(age));
    QPixmap pix ("C:\\Users\\Omar Maged\\OneDrive\\Documents\\Cinema\\welcome.jpg");
    int w = ui->labelImage->width();
    int h = ui->labelImage->height();
    ui->labelImage->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    loginwindow* Loginwindow = new loginwindow(this);
    Loginwindow->show();
}

