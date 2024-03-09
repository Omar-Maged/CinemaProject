#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);

    ui->labelAllFields->setVisible(false);
    ui->labelDOBError->setVisible(false);
    ui->labelRePassError->setVisible(false);
    ui->labelUsernameError->setVisible(false);

}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::on_pushButton_clicked()
{
    ui->labelAllFields->setVisible(false);
    ui->labelDOBError->setVisible(false);
    ui->labelRePassError->setVisible(false);
    ui->labelUsernameError->setVisible(false);

    bool hasError;


    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString ReTypedPassword = ui->lineEditRePassword->text();
    QString month = ui->comboBoxMonth->currentText();
    QString day = ui->lineEditDay->text();
    QString year = ui->lineEditYear->text();
    int Year = year.toInt();



    for (int i = 0; i<usersCount; ++i)
    {
        if (username == usernames[i])
        {
            ui->labelUsernameError->setVisible(true);
            hasError = true;

        }
    }

    if (password != ReTypedPassword)
    {
        ui->labelRePassError->setVisible(true);
        hasError = true;

    }

    if (2024-Year < 12)
    {
        ui->labelDOBError->setVisible(true);
        hasError = true;

    }

    if (username.isEmpty() || password.isEmpty() || ReTypedPassword.isEmpty() || month.isEmpty() || year.isEmpty() || day.isEmpty()  || (!ui->radioButtonMale->isChecked() && !ui->radioButtonFemale->isChecked()) || (!ui->radioButtonAdmin->isChecked() && !ui->radioButtonUser->isChecked()) )
    {
        ui->labelAllFields->setVisible(true);
        hasError = true;
    }

    if (!ui->checkBoxAction->isChecked() && !ui->checkBoxComedy->isChecked() && !ui->checkBoxDrama->isChecked() && !ui->checkBoxHorror->isChecked() && !ui->checkBoxOther->isChecked() && !ui->checkBoxRomance->isChecked() )
    {
        ui->labelAllFields->setVisible(true);
        hasError = true;
    }

    if (!hasError)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = 2024-Year;
        usersCount++;


        WelcomeWindow *welcomewindow = new WelcomeWindow(username, getuserAge(username), this);
        welcomewindow->show();
        this->hide();
    }



}

