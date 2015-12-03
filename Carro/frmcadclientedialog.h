#ifndef FRMCADCLIENTEDIALOG_H
#define FRMCADCLIENTEDIALOG_H

#include <QDialog>
#include "clientecontroller.h"

namespace Ui {
class FrmCadClienteDialog;
}

class FrmCadClienteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmCadClienteDialog(QWidget *parent = 0);
    ~FrmCadClienteDialog();

private slots:
    void on_btCancelar_clicked();

    void on_btGravar_clicked();

    void on_btLimpar_clicked();

private:
    Ui::FrmCadClienteDialog *ui;
    ClienteController *clienteController;
};

#endif // FRMCADCLIENTEDIALOG_H
