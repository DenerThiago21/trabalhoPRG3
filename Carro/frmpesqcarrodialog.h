#ifndef FRMPESQCARRODIALOG_H
#define FRMPESQCARRODIALOG_H

#include <QDialog>
#include <QtSql/QSqlTableModel>

namespace Ui {
class FrmPesqCarroDialog;
}

class FrmPesqCarroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FrmPesqCarroDialog(QWidget *parent = 0);
    ~FrmPesqCarroDialog();

private slots:
    void on_btCancelar_clicked();

    void on_btExcluir_clicked();

private:
    Ui::FrmPesqCarroDialog *ui;
};

#endif // FRMPESQCARRODIALOG_H
