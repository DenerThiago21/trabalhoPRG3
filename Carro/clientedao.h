#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H

#include "cliente.h"
#include <QtSql/QSqlTableModel>

class ClienteDAO
{
public:
    ClienteDAO();
    virtual bool salvar(Cliente *cliente) = 0;
    virtual bool excluir(int id) = 0;
    virtual QVector<Cliente*> listarTodos() = 0;
    virtual QSqlTableModel *getModel() = 0;
    virtual Cliente* buscar(int id) = 0;
};

#endif // CLIENTEDAO_H
