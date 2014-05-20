#include "mainwindowdatabaseengine.h"
#include "ui_mainwindowdatabaseengine.h"

MainWindowDataBaseEngine::MainWindowDataBaseEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowDataBaseEngine)
{
    ui->setupUi(this);
}

MainWindowDataBaseEngine::~MainWindowDataBaseEngine()
{
    delete ui;
}
