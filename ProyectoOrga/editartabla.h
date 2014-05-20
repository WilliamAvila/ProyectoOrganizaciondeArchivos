#ifndef EDITARTABLA_H
#define EDITARTABLA_H

#include <QMainWindow>
#include "metadata.h"
#include "QLabel"
#include "QPointer"
#include "QCheckBox"
#include "QList"
#include "QLineEdit"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "bloque.h"
namespace Ui {
class editarTabla;
}

class editarTabla : public QMainWindow
{
    Q_OBJECT

public:
    explicit editarTabla(QWidget *parent = 0);
    ~editarTabla();



    Metadata *meta;
    Bloque *block;
    QList< QPointer<QLineEdit> > lista_campos;
    QList<int>  lista_tipos;
    void registerToArray();
    int cant_col;
    void readTable();


private slots:
    void on_pushButton_clicked();

private:
    Ui::editarTabla *ui;
};

#endif // EDITARTABLA_H
