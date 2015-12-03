#ifndef COMPRA_H
#define COMPRA_H

#include <QString>
#include "carro.h"
#include "cliente.h"

class Compra
{
public:
    Compra();
    int getCompraID() const;
    void setCompraID(int value);
    QString getFormaPagamento() const;
    void setFormaPagamento(const QString &value);
    QString getValorTotal() const;
    void setValorTotal(const QString &value);

    Cliente *getCliente() const;
    void setCliente(Cliente *value);

    Carro *getCarro() const;
    void setCarro(Carro *value);

private:
    int compraID;
    QString formaPagamento;
    QString valorTotal;
    Cliente *cliente;
    Carro *carro;
};
#endif // COMPRA_H
