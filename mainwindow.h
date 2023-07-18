#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpacerItem>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void tablereset ();
private slots:

    void on_actionNew_triggered();

    void on_actionMerge_triggered();

    void on_actionOpen_triggered();

    void on_actionsave_triggered();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void onfindlinechanged (QString);
    //void on_actionSearch_triggered(); //поиск
    //void on_actionClosefind_triggered();


    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    database *base_;
};
#endif // MAINWINDOW_H
