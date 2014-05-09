#include "creartabla.h"
#include "ui_creartabla.h"
#include <QMessageBox>
#include <QPointer>
#include "bloque.h"
#include <QString>
CrearTabla::CrearTabla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrearTabla)
{
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

CrearTabla::~CrearTabla()
{
    delete ui;
}


void CrearTabla::on_pushButton_2_clicked()
{


    QStringList TiposDatos;
    TiposDatos<<"Numero"
              <<"Texto";
    QPointer <QCheckBox> mi_opciones_llaves = new QCheckBox(this);
    QPointer <QComboBox> mi_opciones_tipo = new QComboBox(this);

    mi_opciones_tipo->addItems(TiposDatos);
    lista_llave.append(mi_opciones_llaves);
    lista_tipos.append(mi_opciones_tipo);
    const int ultima_fila=ui->Campos->rowCount();
    ui->Campos->insertRow(ultima_fila);
    ui->Campos->setCellWidget(ultima_fila,0,mi_opciones_llaves);
     ui->Campos->setCellWidget(ultima_fila,2,mi_opciones_tipo);
}

void CrearTabla::on_Aceptar_clicked()
{
    Bloque *b=new Bloque();
 b->resevando();
    if (ui->lineEdit->text().compare("")==0||ui->Campos->item(0,1)==NULL){
        QMessageBox::information(this,"ERROR","Nombre antes la tabla o agrege un campo ante de guardad");


    }else{

        this->hide();
    }



}
