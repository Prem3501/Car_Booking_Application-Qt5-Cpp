#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "addcar.h"
#include "bookcar.h"

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_addcarButton_2_clicked();

    void on_bookcarButton_2_clicked();

private:
    Ui::mainmenu *ui;
    addCar addCarUi;
    bookCar bookCarUi;
};

#endif // MAINMENU_H
