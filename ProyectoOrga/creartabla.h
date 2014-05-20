#ifndef CREARTABLA_H
#define CREARTABLA_H

#include <QMainWindow>
#include "QPointer"
#include "QList"
#include "QCheckBox"
#include "QComboBox"
#include "QMessageBox"
#include "metadata.h"
#include "field.h"
#include "QDebug"
#include "QLineEdit"

namespace Ui {
class CrearTabla;
}

class CrearTabla : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrearTabla(QWidget *parent = 0);
    ~CrearTabla();

    QList< QPointer<QCheckBox> > lista_llave;
    QList< QPointer<QComboBox> > lista_tipos;
    QList< QPointer<QLineEdit> > lista_nombres;
    char *value;
    int count;
    QMessageBox *box;
    Metadata *meta;
    bool CheckTexCampo();
    void listToChar();



private slots:
    void on_pushButtonAgregarCampos_clicked();

    void on_pushButtonCreartabla_clicked();

    void on_pushButton_clicked();

private:
    Ui::CrearTabla *ui;
};

#endif // CREARTABLA_H
