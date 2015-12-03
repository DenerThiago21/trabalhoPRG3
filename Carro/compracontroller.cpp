#include "compracontroller.h"
#include "daofactory.h"

CompraController::CompraController()
{

}

bool CompraController::salvar(QString formaPagamento, QString valorTotal, Carro *carro, Cliente *cliente)//Cliente cliente, Carro carro
{
    Compra *compra = new Compra();
    compra->setFormaPagamento(formaPagamento);
    compra->setValorTotal(valorTotal);
    compra->setCarro(carro);
    compra->setCliente(cliente);

    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCompraDAO()->salvar(compra);
}

QVector<Compra *> CompraController::listarTodos()
{
    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCompraDAO()->listarTodos();
}

