#ifndef COMPRADAO_H
#define COMPRADAO_H

#include "compra.h"
#include <QVector>
#include <QtSql/QSqlTableModel>

class CompraDAO
{
public:
    CompraDAO();
    virtual bool salvar(Compra *compra) = 0;
    virtual QVector<Compra*> listarTodos() = 0;
   // virtual QSqlTableModel *getModel() = 0;
};

#endif // COMPRADAO_H
