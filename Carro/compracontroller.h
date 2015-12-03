#ifndef COMPRACONTROLLER_H
#define COMPRACONTROLLER_H

#include <QVector>
#include "carro.h"
#include "cliente.h"
#include "compra.h"
class CompraController
{
private:
    QVector<Compra *> listaCompra;
public:
    CompraController();

    bool salvar(QString formaPagamento, QString valorTotal, Carro *carro, Cliente *cliente); //Cliente cliente, Carro carro
    QVector<Compra*> listarTodos();
};

#endif // COMPRACONTROLLER_H
