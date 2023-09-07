#include "bookcar.h"
#include "ui_bookcar.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "QMessageBox"

QVector<QString> getAlltheCarDetails();

bookCar::bookCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookCar)
{
    ui->setupUi(this);
    // we need to read data from carData.txt here
    QVector<QString> carData = getAlltheCarDetails();

    for(int i=0; i<carData.size(); i++){

        ui->selectCarListWidget->addItem(carData[i]);
    }
}

bookCar::~bookCar()
{
    delete ui;
}

void bookCar::on_addCarButton_clicked()
{

}

QVector<QString> getAlltheCarDetails(){

    QVector<QString> getData;

    QFile file("carData.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QTextStream in(&file);

        // Read the file line by line
             while (!in.atEnd()) {
                  QString line = in.readLine();
                  // Process the line as needed
                  // For example, you can print it to the console
                  getData.append(line);
                  qDebug() << line;
             }
    }

    file.close();

    return getData;
}



void bookCar::on_bookcarButton_clicked()
{
    QVector<QString> bookCarDetails;

    bookCarDetails.append(ui->nameLineEdit->text());
    bookCarDetails.append(ui->ageLineEdit->text());
    bookCarDetails.append(ui->pickupLineEdit->text());
    bookCarDetails.append(ui->destinationLineEdit->text());

    bool male = ui->maleRadioButton->isChecked();
    bool female = ui->femaleradioButton->isChecked();

    if(male){
        bookCarDetails.append("male");
    }
    else{
        bookCarDetails.append("female");
    }

    QListWidgetItem *selectedCar = ui->selectCarListWidget->currentItem();
    QString selectedCarDetails = selectedCar->text();

    bookCarDetails.append(selectedCarDetails);

    // store book car data into a file
    QFile file("bookCarData.txt");

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        for(int i=0;i<bookCarDetails.size();i++){
            stream << bookCarDetails[i] << " ";
        }
        stream << "\n";
    }

    file.close();

    QModelIndex currentIndex = ui->selectCarListWidget->currentIndex();
    int currentRow = currentIndex.row();   // 0 1, 2

    QVector<QString> allcarData = getAlltheCarDetails();
    allcarData.remove(currentRow);

    qDebug() << currentRow;

    //rewrite allcardata into carData.txt

    QFile file2("carData.txt");

    if(file2.open(QIODevice::WriteOnly | QIODevice::Text)){  // 0 1
        QTextStream stream(&file2);

        for(int i=0;i<allcarData.size();i++){
            stream << allcarData[i] << "\n";
        }
    }

    file2.close();

    QMessageBox::information(0,"booking status", "Booking Sucessfull");

}


void bookCar::on_exitButton_2_clicked()
{
    QApplication::exit();
}

