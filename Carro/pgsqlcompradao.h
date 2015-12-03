#ifndef PGSQLCOMPRADAO_H
#define PGSQLCOMPRADAO_H

#include "compradao.h"
#include "pgsqldaofactory.h"
#include <QVector>
#include <QtSql/QSqlTableModel>

//#include "clientedao.h"
//#include "carrodao.h"

class PGSQLCompraDAO : public CompraDAO, public PGSQLDAOFactory
{
private:
    QSqlTableModel *model;
    int nextVal();
public:
    PGSQLCompraDAO();
    bool salvar(Compra *compra);
    QVector<Compra*> listarTodos();
    //bool listarTodos();

    QSqlTableModel *getModel();
};

#endif // PGSQLCOMPRADAO_H
