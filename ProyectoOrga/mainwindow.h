#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "creartabla.h"
#include "editartabla.h"
#include "vertabla.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    CrearTabla *tb;
    editarTabla *te;
    VerTabla *vt;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonEditarTabla_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
