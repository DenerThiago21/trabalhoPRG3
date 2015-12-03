#ifndef CARRODAO_H
#define CARRODAO_H

#include "carro.h"
#include <QtSql/QSqlTableModel>

class CarroDAO
{
public:
    CarroDAO();
    virtual bool salvar(Carro *carro) = 0;
    virtual bool excluir(int id) = 0;
    virtual QVector<Carro*> listarTodos() = 0;
    virtual QSqlTableModel *getModel() = 0;
    virtual Carro * buscar(int id) = 0;
};

#endif // CARRODAO_H
