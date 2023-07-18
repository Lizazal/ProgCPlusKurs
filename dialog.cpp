#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, const Bank& b) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(b.Name);
    ui->lineEdit_2->setText(b.Surname);
    ui->lineEdit_3->setText(b.Number);
}

Dialog::~Dialog()
{
    delete ui;
}

Bank Dialog::savedata()
{
    Bank b;
    b.Name=ui->lineEdit->text();
    b.Surname=ui->lineEdit_2->text();
    b.Number=ui->lineEdit_3->text();
    return b;
}
