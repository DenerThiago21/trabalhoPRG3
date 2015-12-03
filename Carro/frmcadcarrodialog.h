#ifndef FRMCADCARRODIALOG_H
#define FRMCADCARRODIALOG_H

#include <QDialog>
#include "carrocontroller.h"

namespace Ui {
class FrmCadCarroDialog;
}

class FrmCadCarroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmCadCarroDialog(QWidget *parent = 0);
    ~FrmCadCarroDialog();

private slots:
    void on_btCancelar_clicked();

    void on_btGravar_clicked();

    void on_btLimpar_clicked();

private:
    Ui::FrmCadCarroDialog *ui;
    CarroController *carroController;
};

#endif // FRMCADCARRODIALOG_H
