#include "creartabla.h"
#include "ui_creartabla.h"

CrearTabla::CrearTabla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrearTabla)
{
    ui->setupUi(this);
    this->setWindowTitle("Crear Tabla");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    meta=new Metadata();
    this->value=new char[200];
    this->count=0;
}

CrearTabla::~CrearTabla()
{
    delete ui;
}

void CrearTabla::on_pushButtonAgregarCampos_clicked()
{

    if(this->CheckTexCampo()){

    QStringList TiposDatos;
    TiposDatos<<"Numero"<<"Texto";
    QPointer <QCheckBox> mi_opciones_llaves = new QCheckBox(this);
    QPointer <QComboBox> mi_opciones_tipo = new QComboBox(this);
    QPointer <QLineEdit> nombre_campo = new QLineEdit(this);


    mi_opciones_tipo->addItems(TiposDatos);
    lista_llave.append(mi_opciones_llaves);
    lista_nombres.append(nombre_campo);
    lista_tipos.append(mi_opciones_tipo);
    const int ultima_fila=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(ultima_fila);
    ui->tableWidget->setCellWidget(ultima_fila,0,mi_opciones_llaves);
    ui->tableWidget->setCellWidget(ultima_fila,1,nombre_campo);

    ui->tableWidget->setCellWidget(ultima_fila,2,mi_opciones_tipo);
    }
    /*char*ar="miarchivo.wa";
    char* test="test";
    Field*campo=new Field;
    campo->setString(test);
    meta->insertEncabezado(campo,ar);
    meta->readEncabezado(ar);*/


}
bool CrearTabla::CheckTexCampo(){
    const int ultima_fila=ui->tableWidget->rowCount();
    if(ultima_fila!=0){
    if(this->lista_nombres.at(ultima_fila-1).data()->text()==""){
        QMessageBox*box=new QMessageBox();
        box->setWindowTitle("Warning");
        box->setText("Ingrese Nombre Campo");
        box->show();
        return false;
    }
    else{

        /*char *val=new char[25];
        val=this->lista_nombres.at(ultima_fila-1).data()->text().toUtf8().data();
        //qDebug()<<"se agrego"<<val;
        memcpy(&(this->value[0]),val,25);

        count+=25;

         qDebug()<<(&value[0]);*/
          ui->tableWidget->cellWidget(ultima_fila-1,0)->setEnabled(false);
          ui->tableWidget->cellWidget(ultima_fila-1,1)->setEnabled(false);
          ui->tableWidget->cellWidget(ultima_fila-1,2)->setEnabled(false);
          ui->tableWidget->cellWidget(ultima_fila-1,0)->setToolTip("It Can't Edit key");
          ui->tableWidget->cellWidget(ultima_fila-1,1)->setToolTip("It Can't Edit Name");
          ui->tableWidget->cellWidget(ultima_fila-1,2)->setToolTip("It Can't Edit Type");

        return true;

    }
    return false;
       }

    return true;


}

void CrearTabla::listToChar()
{
    this->meta=new Metadata();

   /*char * byteArray=new char[25];
    int j=0;
    memcpy(&byteArray[0],&value,25);*/
    char *tableName=new char[25];
    tableName= ui->lineEditNombreTabla->text().toUtf8().data();
    memcpy(&(this->value[count]),tableName,25);
    count+=25;

    int tam=this->lista_nombres.size()-1;

    memcpy(&(this->value[count]),&tam,4);
    count+=4;



    for(int i=0;i<this->lista_nombres.size()-1;i++){
        char *val=new char[25];
        val=this->lista_nombres.at(i).data()->text().toUtf8().data();
        memcpy(&(this->value[count]),val,25);
        count+=25;

    }

    for(int i=0;i<this->lista_tipos.size()-1;i++){
        int type =this->lista_tipos.at(i).data()->currentIndex();
        memcpy(&(this->value[count]),&type,4);
        count+=4;
     }

    meta->insertEncabezado(value,"miarchivo.wa",200);
}

void CrearTabla::on_pushButtonCreartabla_clicked()
{

    if(ui->lineEditNombreTabla->text()==""){
        box=new QMessageBox();
        box->setWindowTitle("Warning");
        box->setText("Ingrese Nombre Tabla");
        box->show();
    }
        else{
        this->listToChar();
        box=new QMessageBox();
        box->setWindowTitle("Success");
        box->setText("Tabla Creada");
        box->show();
        this->hide();

    }
}

void CrearTabla::on_pushButton_clicked()
{
    this->close();

}
