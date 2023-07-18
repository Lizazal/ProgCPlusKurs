#include "database.h"
#include "mainwindow.h"

database::database (QObject *parent):QObject (parent), saved(true){}
database::~database() {}
void database::add (const Bank &b)
{
    saved=false;
    v.push_back(b);
}
void database::remove (int n)
    {
        saved=false;
        v.removee(n);
    }
void database::save (const QString &fileName)
{
    if (fileName.isEmpty())
        return;
    else
    {
        QFile file (fileName);
        if (!file.open(QIODevice::WriteOnly))
            return;
        else
        {
            QString str ("");
            typename Vector <Bank>::iterator iterate;
            for (iterate=v.begin(); iterate!=v.end(); ++iterate)
            {
                str.append(iterate->Name);
                str.append("\t");
                str.append(iterate->Surname);
                str.append("\t");
                str.append(iterate->Number);
                str.append("\n");
            }
            QByteArray ar;
            ar.append(str);
            file.write(ar);
        }
        file.close();
        saved=true;
    }
}
void database::load (const QString &fileName)
{
    if (fileName.isEmpty())
        return;
    else
    {
        QFile file (fileName);
        if (!file.open(QIODevice::ReadOnly))
            return;
        QTextStream stream (&file);
        QString str;
        QStringList fields;
        Bank tmp;
        while (!stream.atEnd())
        {
            str=stream.readLine();
            //str=str.simplified();
            fields=str.split("\t");
            tmp.Name=fields[0];
            tmp.Surname=fields[1];
            tmp.Number=fields[2];
            add(tmp);
        }
        file.close();
        saved=true;
     }
}
    bool database::isSaved()
    {
        return saved;
    }
    void database::clear()
    {
        saved=false;
        v.clear();
    }
    void database::addtotable(QTableWidget *t)
    {
        typename Vector<Bank>::iterator iter=v.begin();
        for (iter=v.begin(); iter!=v.end(); ++iter)
        {
            t->setRowCount(t->rowCount()+1);
            t->setItem(t->rowCount()-1, 0, new QTableWidgetItem(iter->Name));
            t->setItem(t->rowCount()-1, 1, new QTableWidgetItem(iter->Surname));
            t->setItem(t->rowCount()-1, 2, new QTableWidgetItem(iter->Number));
        }
    }
    void database::summ(const QString &fileName)
    {
        if (fileName.isEmpty())
            return;
       else
        {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly))
            {
                return;
            }
            QTextStream stream (&file);
            QString str;
            QStringList fields;
            Bank tmp;
            while (!stream.atEnd())
            {
                str=stream.readLine();
                //str=str.simplified();
                fields=str.split("\t");
                tmp.Name=fields[0];
                tmp.Surname=fields[1];
                tmp.Number=fields[2];
                add(tmp);
            }
            file.close();
            saved=false;
    }
 }
    void database::find(QString s, QTableWidget *t)
    {
        typename Vector<Bank>::iterator iter;
        for (iter=v.begin(); iter!=v.end(); ++iter)
        {
            if (iter->Name.contains(s)||iter->Surname.contains(s)||iter->Number.contains(s))
            {
                t->setRowCount(t->rowCount()+1);
                t->setItem(t->rowCount()-1, 0, new QTableWidgetItem(iter->Name));
                t->setItem(t->rowCount()-1, 1, new QTableWidgetItem(iter->Surname));
                t->setItem(t->rowCount()-1, 2, new QTableWidgetItem(iter->Number));
            }
        }
    }
void database::change(int n)
{
    Dialog dialog (nullptr, v[n]);
    int result = dialog.exec();
    if (QDialog::Accepted == result)
    {
        saved=false;
        v[n]=dialog.savedata();
    }
}
