#ifndef BD_H
#define BD_H

#include <QMainWindow>

namespace Ui {
class BD;
}

class BD : public QMainWindow
{
    Q_OBJECT

public:
    explicit BD(QWidget *parent = 0);
    ~BD();

private slots:
    void on_CrearTabla_clicked();

private:
    Ui::BD *ui;
};

#endif // BD_H
