#include "bd.h"
#include "ui_bd.h"
#include "creartabla.h"
BD::BD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BD)
{
    ui->setupUi(this);
}

BD::~BD()
{
    delete ui;
}

void BD::on_CrearTabla_clicked()
{

   CrearTabla ctv;
   ctv.setModal(true);
   ctv.exec();

}
