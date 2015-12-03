#include "frmpesqcarrodialog.h"
#include "ui_frmpesqcarrodialog.h"

#include "daofactory.h"
#include <QModelIndex>
#include <QMessageBox>

FrmPesqCarroDialog::FrmPesqCarroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmPesqCarroDialog)
{
    ui->setupUi(this);

    ui->carroView->setModel(DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->getModel());
    ui->carroView->show();
}

FrmPesqCarroDialog::~FrmPesqCarroDialog()
{
    delete ui;
}

void FrmPesqCarroDialog::on_btCancelar_clicked()
{
    this->close();
}

void FrmPesqCarroDialog::on_btExcluir_clicked()
{
    QMessageBox confirm;
    QMessageBox msgShow;

    confirm.setText("Você deseja realmente exluir esse registro?");
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = confirm.exec();

    switch(ret)
    {
        case QMessageBox::Yes :
        {
            QModelIndex linha = ui->carroView->currentIndex();
            int id = linha.model()->data(linha.model()->index(linha.row(),0), Qt::DisplayRole).toInt();

            if(DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->excluir(id))
            {
                ui->carroView->setRowHidden(linha.row(), true);
                msgShow.setText("O Registro Foi Excluido com SUCESSO!");
            }
            else
            {
                msgShow.setText("O Registro não foi Excluido");
            }
            msgShow.exec();
            break;
        }
        case QMessageBox::No :
        {
            break;
        }
    }
}
