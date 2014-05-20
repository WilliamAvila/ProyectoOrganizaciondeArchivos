#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestor Base de datos");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tb= new CrearTabla();
    tb->show();

}

void MainWindow::on_pushButtonEditarTabla_clicked()
{
    te= new editarTabla();
    te->show();

}

void MainWindow::on_pushButton_2_clicked()
{     vt= new VerTabla();
      vt->show();

}
