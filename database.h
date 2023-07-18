#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QFileDialog>
#include <QString>
#include <algorithm>
#include "vector.h"
#include "dialog.h"


class database:public QObject
{
    Q_OBJECT
public:
    explicit database (QObject *parent = nullptr);
    ~database ();
    void save (const QString &fileName);
    void load (const QString &fileName);
    void summ (const QString &fileName);
    void add (const Bank& b);
    void remove (int n);
    void find (QString s, QTableWidget *t);
    void addtotable (QTableWidget *t);
    void clear ();
    void change(int n);
private:
    Vector <Bank> v;
    bool saved;
public slots:
    bool isSaved();
};
#endif
