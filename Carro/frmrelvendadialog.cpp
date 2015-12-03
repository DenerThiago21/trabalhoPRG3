#include "frmrelvendadialog.h"
#include "ui_frmrelvendadialog.h"


FrmRelVendaDialog::FrmRelVendaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmRelVendaDialog)
{
    ui->setupUi(this);
    this->compraController = new CompraController();

    QVector<Compra*> listaCompras = compraController->listarTodos();

    QString comprasText = "Lista de Compras Cadastradas\n\n--------------------------------------------------------------------------------\n";
    for (int i = 0; i < listaCompras.size(); i++) {
        comprasText += "COMPRA DE NUMERO: " + QString::number(listaCompras.at(i)->getCompraID()) + "\n";
        comprasText += "--------------------------------------------------------------------------------\n";
        comprasText += "Tipo Pagamento " + listaCompras.at(i)->getFormaPagamento() + "\n";
        comprasText += "Valor Total: " + listaCompras.at(i)->getValorTotal() + "\n";
        comprasText += "------------------DADOS CARRO-------------------------------------------\n";
        comprasText += "  Id carro: " +QString::number(listaCompras.at(i)->getCarro()->getCaroID()) + "\n";
        comprasText += "  nome carro: " +listaCompras.at(i)->getCarro()->getNome() + "\n";
        comprasText += "  ano: " + QString::number(listaCompras.at(i)->getCarro()->getAno()) + "\n";
        comprasText += "  tipo: " + listaCompras.at(i)->getCarro()->getTipo() + "\n";
        comprasText += "----------------------DADOS CLIENTE--------------------------------------\n";
        comprasText += "     Cliente id: " + QString::number(listaCompras.at(i)->getCliente()->getClienteID())+"\n";
        comprasText += "     Nome: " +listaCompras.at(i)->getCliente()->getNome() + "\n";
        comprasText += "     CPF: " + listaCompras.at(i)->getCliente()->getCPF() + "\n";
        comprasText += "     RG: " + listaCompras.at(i)->getCliente()->getRG() + "\n";
        comprasText += "--------------------------------------------------------------------------------\n\n";
    }

    ui->edRelVenda->appendPlainText(comprasText);
    ui->edRelVenda->setReadOnly(true);


}

FrmRelVendaDialog::~FrmRelVendaDialog()
{
    delete ui;
}

void FrmRelVendaDialog::on_btCancelar_clicked()
{
    this->close();
}
