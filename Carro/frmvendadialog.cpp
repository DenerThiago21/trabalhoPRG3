#include "frmvendadialog.h"
#include "ui_frmvendadialog.h"
#include "pgsqlcarrodao.h"
#include "pgsqlclientedao.h"
#include <QVector>
#include <QMessageBox>


FrmVendaDialog::FrmVendaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmVendaDialog)
{
    ui->setupUi(this);

    carroController = new CarroController();

    carros = carroController->listarTodos();

    for(int i = 0; i < carros.size(); i++)
    {
        ui->cbCarro->addItem(QString::number(carros.at(i)->getCaroID()) + " - " + carros.at(i)->getNome());
    }

    clienteController = new ClienteController();

    clientes = clienteController->listarTodos();

    for(int i = 0; i < clientes.size(); i++)
    {
        ui->cbCliente->addItem(QString::number(clientes.at(i)->getClienteID()) + " - " + clientes.at(i)->getNome());
    }


//pegar ui->cbcliente->currentIndex; retorna o indece
//clientes.at(valor da linha anterior)
}

FrmVendaDialog::~FrmVendaDialog()
{
    delete ui;
}

void FrmVendaDialog::on_btCancelar_clicked()
{
    this->close();
}



void FrmVendaDialog::on_btOk_clicked()
{
    int indiceCliente = ui->cbCliente->currentIndex();
    cliente = clientes.at(indiceCliente);
    //FrmVendaDialog frmVendaDialog = new FrmVendaDialog();
    ui->edNomeCliente->setText(cliente->getNome());
    ui->edRGCliente->setText(cliente->getRG());
    ui->edCPFCliente->setText(cliente->getCPF());
    ui->edNascCliente->setText(cliente->getDataNasc());
    ui->edTelefone->setText(cliente->getTelefone1());
    ui->edEmailCliente->setText(cliente->getEmail());

}

void FrmVendaDialog::on_btOk_2_clicked()
{
    int indiceCarro = ui->cbCarro->currentIndex();
    carro = carros.at(indiceCarro);

    ui->edNomeCarro->setText(carro->getNome());
    QString ano = QString::number(carro->getAno());
    ui->edAnoCarro->setText(ano);
    ui->edMarca->setText(carro->getMarca());
    ui->edTipo->setText(carro->getTipo());


}

void FrmVendaDialog::on_btConfirmar_clicked()
{
    int indiceCarro = ui->cbCarro->currentIndex();
    carro = carros.at(indiceCarro);

    int indiceCliente = ui->cbCliente->currentIndex();
    cliente = clientes.at(indiceCliente);

    QString formaPagamento = ui->edFormaPgto->text();
    QString valorTotal = ui->edValorTotal->text();

    QMessageBox confirm;
    QMessageBox msgShow;

    confirm.setText("Você deseja realmente Confirmar a Compra?");
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    int ret = confirm.exec();

    switch(ret) {
        case QMessageBox::Yes : {
            if (compraController->salvar(formaPagamento, valorTotal, carro, cliente)) {
                msgShow.setText("Compra efetuada com sucesso!");
                this->close();
            } else {
                msgShow.setText("A Compra não foi efetuada");
            }
            msgShow.exec();
            break;
        }
        case QMessageBox::No : {
            this->close();
            break;
        }
    }

}
