#include "creartablaventana.h"
#include "ui_creartablaventana.h"
#include <QMessageBox>
#include <QComboBox>

CrearTablaVentana::CrearTablaVentana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrearTablaVentana)
{

}

CrearTablaVentana::~CrearTablaVentana()
{
    delete ui;
}

void CrearTablaVentana::on_NuevoCampo_clicked()
{

  }

void CrearTablaVentana::on_pushButton_clicked()
{

    if (ui->NombreTabla->text().compare("")==0){
        QMessageBox::information(this,"","Nombre la tabla ante de guardar ");
    }
}

