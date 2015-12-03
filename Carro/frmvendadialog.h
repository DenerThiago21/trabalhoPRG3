#ifndef FRMVENDADIALOG_H
#define FRMVENDADIALOG_H

#include <QDialog>
#include "compracontroller.h"
#include <QVector>
#include "cliente.h"
#include "carro.h"
#include "carrocontroller.h"
#include "clientecontroller.h"
#include "carro.h"
#include "cliente.h"

namespace Ui {
class FrmVendaDialog;
}

class FrmVendaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmVendaDialog(QWidget *parent = 0);
    ~FrmVendaDialog();

    Carro *getCarro() const;
    void setCarro(Carro *value);

private slots:
    void on_btCancelar_clicked();

    void on_btOk_clicked();

    void on_btOk_2_clicked();

    void on_btConfirmar_clicked();

private:
    Ui::FrmVendaDialog *ui;
    CompraController *compraController;
    QVector<Cliente*> clientes;
    QVector<Carro*> carros;
    CarroController *carroController;
    ClienteController *clienteController;
    Carro *carro;
    Cliente *cliente;
};

#endif // FRMVENDADIALOG_H
