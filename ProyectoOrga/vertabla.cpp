#include "vertabla.h"
#include "ui_vertabla.h"

VerTabla::VerTabla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerTabla)
{
    ui->setupUi(this);
    this->setWindowTitle("Ver Tabla");
    this->readMeadata();
    this->readRegisters();
}

VerTabla::~VerTabla()
{
    delete ui;
}

void VerTabla::readMeadata()
{
    char *valor=new char[200];
    meta->readEncabezado("miarchivo.wa",valor,200);



    memcpy(&cant_col,&valor[25],4);

    ui->tableWidget->setColumnCount(cant_col);


        int cont=29;
        for(int i=0;i<cant_col;i++){
            QTableWidgetItem *item=new QTableWidgetItem();
            char *nombreCol=new char[25];


            memcpy(nombreCol,&valor[cont],25);
            cont+=25;

            item->setText(nombreCol);



            ui->tableWidget->setHorizontalHeaderItem(i,item);

        }


        for(int i=0;i<cant_col;i++){
           int tipo;

            memcpy(&tipo,&valor[cont],4);
            cont+=4;
            qDebug()<<tipo;

            this->lista_tipos.append(tipo);
        }

}

void VerTabla::readRegisters()
{
     block =new Bloque();
     int size=block->sizeBloques("miarchivo.wa");
     qDebug()<<size;
     char *registros=new char[size];

     block->readRegister("miarchivo.wa",registros,size);
     int cantR=block->getCantR();
     int num;
     memcpy(&num,&registros[0],4);
     qDebug()<<num;



      int cont=0;




      for(int j=0;j<cantR;j++){
          cont=j*200;
          const int ultima_fila=ui->tableWidget->rowCount();
          ui->tableWidget->insertRow(ultima_fila);
          for(int i=0;i<cant_col;i++){
              if(this->lista_tipos.at(i)==0){
                  int num;
                  memcpy(&num,&registros[cont],4);
                  cont+=4;
                  QPointer <QLabel> t1 = new QLabel(this);
                  t1.data()->setText(QString::number(num));
                  this->lista_campos.append(t1);
                  ui->tableWidget->setCellWidget(ultima_fila,i,t1);

               }else{
                  char *campo=new char[25];
                  memcpy(campo,&registros[cont],25);
                  cont+=25;
                  QPointer <QLabel> t1 = new QLabel(this);
                  t1.data()->setText(campo);
                  this->lista_campos.append(t1);
                  ui->tableWidget->setCellWidget(ultima_fila,i,t1);

              }

          }
          cont=0;
        }




     /*for(int i=0;i<cant_col;i++){
         QPointer <QLabel> t1 = new QLabel(this);
         this->lista_campos.append(t1);
         ui->tableWidget->setCellWidget(ultima_fila,i,t1);

     }*/

}



