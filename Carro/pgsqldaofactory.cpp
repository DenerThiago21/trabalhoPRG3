#include "pgsqldaofactory.h"
#include "pgsqlcarrodao.h"
#include "pgsqlclientedao.h"
#include "pgsqlcompradao.h"

PGSQLDAOFactory::PGSQLDAOFactory()
{
    if(!QSqlDatabase::database().isOpen())
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("TrabalhoA3");
        db.open();
    }
}

QSqlDatabase PGSQLDAOFactory::getConexao()
{
    return QSqlDatabase::database();
}

CarroDAO* PGSQLDAOFactory::getCarroDAO()
{
    return new PGSQLCarroDAO();
}

ClienteDAO* PGSQLDAOFactory::getClienteDAO()
{
    return new PGSQLClienteDAO();
}

CompraDAO* PGSQLDAOFactory::getCompraDAO()
{
    return new PGSQLCompraDAO();
}
