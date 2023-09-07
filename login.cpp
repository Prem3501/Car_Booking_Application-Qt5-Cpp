#include "login.h"
#include "ui_login.h"
#include "QDebug"
#include "QMessageBox"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_exitButton_clicked()
{
    QApplication::quit();
}


void login::on_loginButton_clicked()
{
    QString userid = ui->useridLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if(userid == "admin"){
        if(password == "admin123"){
            mainmenuUi.show();
            login::close();
        }
        else{
            QMessageBox::information(0,"Authentication", "Incorrect Password !!!");
        }
    }
    else{

        QMessageBox::information(0,"Authentication", "Incorrect UserID !!!");
    }
}

