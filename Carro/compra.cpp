#include "compra.h"

Compra::Compra()
{

}

int Compra::getCompraID() const
{
    return compraID;
}

void Compra::setCompraID(int value)
{
    compraID = value;
}

QString Compra::getFormaPagamento() const
{
    return formaPagamento;
}

void Compra::setFormaPagamento(const QString &value)
{
    formaPagamento = value;
}

QString Compra::getValorTotal() const
{
    return valorTotal;
}

void Compra::setValorTotal(const QString &value)
{
    valorTotal = value;
}
Cliente *Compra::getCliente() const
{
    return cliente;
}

void Compra::setCliente(Cliente *value)
{
    cliente = value;
}
Carro *Compra::getCarro() const
{
    return carro;
}

void Compra::setCarro(Carro *value)
{
    carro = value;
}



