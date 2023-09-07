#include "addcar.h"
#include "ui_addcar.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

addCar::addCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCar)
{
    ui->setupUi(this);
    ui->carTypeListWidget->addItem("Mini");
    ui->carTypeListWidget->addItem("Sedan");
    ui->carTypeListWidget->addItem("SUV");
    ui->carTypeListWidget->addItem("Premium");
}

addCar::~addCar()
{
    delete ui;
}

void addCar::on_addCarButton_clicked()
{
    QVector<QString> carData; // 0 1 2 3

    carData.append(ui->carnoLineEdit->text());
    carData.append(ui->brandLineEdit->text());
    carData.append(ui->fareLineEdit->text());

    QListWidgetItem *selectedCarType = ui->carTypeListWidget->currentItem();
    carData.append(selectedCarType->text());

    // store car data into a file
    QFile file("carData.txt");

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        for(int i=0;i<carData.size();i++){
            stream << carData[i] << " ";
        }
        stream << "\n";
    }

    file.close();

    qDebug() << "Data written into file sucesfully";


}


void addCar::on_exitButton_2_clicked()
{
    QApplication::exit();
}

