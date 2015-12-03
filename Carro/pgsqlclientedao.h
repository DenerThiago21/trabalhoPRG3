#ifndef PGSQLCLIENTEDAO_H
#define PGSQLCLIENTEDAO_H

#include "clientedao.h"
#include "pgsqldaofactory.h"

#include <QtSql/QSqlTableModel>
#include <QVector>

class PGSQLClienteDAO : public ClienteDAO, public PGSQLDAOFactory
{
private:
    QSqlTableModel *model;
    int nextVal();
public:
    PGSQLClienteDAO();
    bool salvar(Cliente *cliente);
    bool excluir(int id);
    QVector<Cliente*> listarTodos();
    Cliente * buscar(int id);

    QSqlTableModel *getModel();
};

#endif // PGSQLCLIENTEDAO_H
