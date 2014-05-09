#ifndef CREARTABLA_H
#define CREARTABLA_H

#include <QDialog>
#include <QPointer>
#include <QComboBox>
#include <QCheckBox>
namespace Ui {
class CrearTabla;
}

class CrearTabla : public QDialog
{
    Q_OBJECT
QList< QPointer<QCheckBox> > lista_llave;
QList< QPointer<QComboBox> > lista_tipos;
public:
    explicit CrearTabla(QWidget *parent = 0);
    ~CrearTabla();


private slots:
void on_pushButton_2_clicked();

void on_Aceptar_clicked();

private:
    Ui::CrearTabla *ui;
};

#endif // CREARTABLA_H
