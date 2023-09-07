#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_addcarButton_2_clicked()
{
    addCarUi.show();
}


void mainmenu::on_bookcarButton_2_clicked()
{
    bookCarUi.show();
}


void mainmenu::on_exitButton_2_clicked()
{
    QApplication::exit();
}

