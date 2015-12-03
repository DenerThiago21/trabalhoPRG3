#include "frmpesqclientedialog.h"
#include "ui_frmpesqclientedialog.h"

#include "daofactory.h"
#include <QModelIndex>
#include <QMessageBox>


FrmPesqClienteDialog::FrmPesqClienteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmPesqClienteDialog)
{
    ui->setupUi(this);

    ui->clienteView->setModel(DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->getModel());
    ui->clienteView->show();
}

FrmPesqClienteDialog::~FrmPesqClienteDialog()
{
    delete ui;
}

void FrmPesqClienteDialog::on_btCancelar_clicked()
{
    this->close();
}

void FrmPesqClienteDialog::on_btExcluir_clicked()
{
    QMessageBox confirm;
    QMessageBox msgShow;

    confirm.setText("Você deseja realmente excluir o Registro?");
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = confirm.exec();

    switch(ret) {
        case QMessageBox::Yes : {
            QModelIndex linha = ui->clienteView->currentIndex();
            int id = linha.model()->data(linha.model()->index(linha.row(),0), Qt::DisplayRole).toInt();

            if (DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->excluir(id))
            {
                ui->clienteView->setRowHidden(linha.row(), true);
                msgShow.setText("O Registro foi excluido com SUCESSO!");
            }
            else
            {
                msgShow.setText("O Registro não foi excluido!");
            }
            msgShow.exec();
            break;
        }
        case QMessageBox::No : {

            break;
        }
    }
}
