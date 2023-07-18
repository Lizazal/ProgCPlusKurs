#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "struct.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, const Bank& b=Bank());
    ~Dialog();
    Bank savedata();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
