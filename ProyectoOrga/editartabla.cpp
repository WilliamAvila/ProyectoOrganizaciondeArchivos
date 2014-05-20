#include "editartabla.h"
#include "ui_editartabla.h"

editarTabla::editarTabla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editarTabla)
{
    QPointer <QLabel> tablename = new QLabel(this);
    ui->setupUi(this);
    this->setWindowTitle("Editar Tabla");

    ui->tableWidgetTableName->setCellWidget(0 ,0,tablename);

    ui->tableWidgetTableName->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetTableEdit->horizontalHeader()->setStretchLastSection(true);


    meta=new Metadata();
    this->readTable();

}

void editarTabla::readTable()
{   char *valor=new char[200];
    meta->readEncabezado("miarchivo.wa",valor,200);
    QPointer <QLabel> tablename = new QLabel(this);
    tablename.data()->setText(valor);


    memcpy(&cant_col,&valor[25],4);
    const int ultima_fila=ui->tableWidgetTableName->rowCount();

    qDebug()<<cant_col;
    ui->tableWidgetTableName->insertRow(ultima_fila);
    ui->tableWidgetTableName->setCellWidget(ultima_fila ,0,tablename);


    const int ultima_fila2=ui->tableWidgetTableEdit->rowCount();
    ui->tableWidgetTableEdit->insertRow(ultima_fila2);
    ui->tableWidgetTableEdit->setColumnCount(cant_col);


        int cont=29;
        for(int i=0;i<cant_col;i++){
            QTableWidgetItem *item=new QTableWidgetItem();
            char *nombreCol=new char[25];


            memcpy(nombreCol,&valor[cont],25);
            cont+=25;

            item->setText(nombreCol);



            ui->tableWidgetTableEdit->setHorizontalHeaderItem(i,item);

            QPointer <QLineEdit> t1 = new QLineEdit(this);
            this->lista_campos.append(t1);
            ui->tableWidgetTableEdit->setCellWidget(ultima_fila2,i,t1);

        }


        for(int i=0;i<cant_col;i++){
           int tipo;

            memcpy(&tipo,&valor[cont],4);
            cont+=4;
            qDebug()<<tipo;

            this->lista_tipos.append(tipo);
        }

}

editarTabla::~editarTabla()
{
    delete ui;
}

void editarTabla::registerToArray()
{   char * registro=new char[200];
    int cont=0;

    for(int i=0;i<cant_col;i++){
        if(this->lista_tipos.at(i)==0){
            int num =this->lista_campos.at(i).data()->text().toInt();
            memcpy(&registro[cont],&num,4);
            cont+=4;

        }else{
           char *campo=new char[25];
           campo=this->lista_campos.at(i).data()->text().toUtf8().data();
           memcpy(&registro[cont],campo,25);
           cont+=25;



        }



    }

    block=new Bloque();

    block->writeRegister(registro,"miarchivo.wa",200);



}

void editarTabla::on_pushButton_clicked()
{ QMessageBox*box=new QMessageBox();
    bool pass=false;
    for(int i=0;i<cant_col;i++){

        if(this->lista_campos.at(i).data()->text()==""){

            box->setWindowTitle("Warning");
            box->setText("Ingrese Todos los Campos");
            box->show();

        }
        else{
            this->hide();
            pass=true;

        }


    }
    if(pass)
        this->registerToArray();

}
