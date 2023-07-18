#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    base_ = new database();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    if (!base_->isSaved())
        if (QMessageBox::question(this, "", "Do you want to save the changes?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
            on_actionsave_triggered();
    base_->clear();
    tablereset();
}

void MainWindow::on_actionMerge_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Merge File", "", "*.txt");
    base_->summ(filename);
    tablereset();
    base_->addtotable(ui->tableWidget);
    ui->statusBar->showMessage("Merged");
}

void MainWindow::on_actionOpen_triggered()
{
    if (!base_->isSaved())
        if (QMessageBox::question(this, "", "Do you want to save the changes?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
            on_actionsave_triggered();
    QString filename = QFileDialog::getOpenFileName(this, "OpenFile", "", "*.txt");
    base_->clear();
    tablereset();
    base_->load(filename);
    base_->addtotable(ui->tableWidget);
}

void MainWindow::on_actionsave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save File", "", "*.txt");
    base_->save(filename);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "База данных, характеризующая клиента банка.\nВыполнила студентка группы ИКПИ-72 Залевская Елизавета");
}

void MainWindow::on_actionExit_triggered()
{
    if (!base_->isSaved())
        if (QMessageBox::question(this, "", "Do you want to save the changes?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
            on_actionsave_triggered();
   if (QMessageBox::question(this, "", "Do you want to exit?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
       close();
}

void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
    int result = dialog.exec();
    if (QDialog::Accepted==result)
    {
        base_->add(dialog.savedata());
        tablereset();
        base_->addtotable(ui->tableWidget);
    }
    ui->statusBar->showMessage("Added");
}


void MainWindow::on_pushButton_2_clicked()
{
    if (QMessageBox::question(this, "", "Are you sure?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
    {
        if (!ui->tableWidget->selectedItems().isEmpty())
        {
            int numRow=ui->tableWidget->selectedItems().last()->row();
            ui->tableWidget->removeRow(numRow);
            base_->remove(numRow);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (!ui->tableWidget->selectedItems().isEmpty())
        base_->change(ui->tableWidget->selectedItems().back()->row());
    tablereset();
    base_->addtotable(ui->tableWidget);
}

void MainWindow::tablereset()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    QStringList s;
    s.append("Name");
    s.append("Surname");
    s.append("Number");
    ui->tableWidget->setHorizontalHeaderLabels(s);
}

/*
//удаление записи
void MainWindow::on_pushButton_2_clicked()
{
    int selected = ui->tableWidget->currentRow();
    if (selected>=0)
        if (QMessageBox::question(this, "", "Are you sure?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
            ui->tableWidget->removeRow(selected);
}*/

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if (ui->lineEdit->text()=="")
    {
        ui->tableWidget->setCurrentCell(0,0);
        ui->tableWidget->clearSelection();
        return;
    }
    QTableWidgetItem *item;
    QList<QTableWidgetItem*> found = ui -> tableWidget ->findItems(ui->lineEdit->text(), Qt::MatchContains);
    foreach (item, found)
    {
        if (item->column()!=-1)
        {
            ui->tableWidget->clearSelection();
            ui->tableWidget->setItemSelected(item, true);
            ui->tableWidget->setCurrentCell(item->row(), item->column());
            break;
        }
    }
}
