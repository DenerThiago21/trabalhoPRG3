#ifndef FRMPESQCLIENTEDIALOG_H
#define FRMPESQCLIENTEDIALOG_H

#include <QDialog>
#include <QtSql/QSqlTableModel>

namespace Ui {
class FrmPesqClienteDialog;
}

class FrmPesqClienteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmPesqClienteDialog(QWidget *parent = 0);
    ~FrmPesqClienteDialog();

private slots:
    void on_btCancelar_clicked();

    void on_btExcluir_clicked();

private:
    Ui::FrmPesqClienteDialog *ui;
};

#endif // FRMPESQCLIENTEDIALOG_H
