#ifndef VERTABLA_H
#define VERTABLA_H

#include <QDialog>
#include "bloque.h"
#include "metadata.h"
#include <QList>
#include <QTableWidgetItem>
#include <QLabel>
#include <QPointer>

namespace Ui {
class VerTabla;
}

class VerTabla : public QDialog
{
    Q_OBJECT

public:
    explicit VerTabla(QWidget *parent = 0);

    Metadata *meta;
    Bloque *block;
    QList<int> lista_tipos;
    QList< QPointer<QLabel> > lista_campos;
    void readMeadata();
    void readRegisters();
    int cant_col;

    ~VerTabla();

private:
    Ui::VerTabla *ui;
};

#endif // VERTABLA_H
