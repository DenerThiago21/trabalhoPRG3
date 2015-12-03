#ifndef PGSQLDAOFACTORY_H
#define PGSQLDAOFACTORY_H

#include "daofactory.h"
#include "carrodao.h"
#include "clientedao.h"
#include "compradao.h"

#include <QtSql/QSqlTableModel>

class PGSQLDAOFactory : public DAOFactory
{
public:
    PGSQLDAOFactory();
    QSqlDatabase getConexao();

    CarroDAO *getCarroDAO();
    CompraDAO *getCompraDAO();
    ClienteDAO *getClienteDAO();
};

#endif // PGSQLDAOFACTORY_H
