#ifndef FRMRELVENDADIALOG_H
#define FRMRELVENDADIALOG_H

#include <QDialog>

#include "compracontroller.h"

namespace Ui {
class FrmRelVendaDialog;
}

class FrmRelVendaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmRelVendaDialog(QWidget *parent = 0);
    ~FrmRelVendaDialog();

private slots:
    void on_btCancelar_clicked();

private:
    Ui::FrmRelVendaDialog *ui;
    CompraController *compraController;

};

#endif // FRMRELVENDADIALOG_H
