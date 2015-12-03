#ifndef PGSQLCARRODAO_H
#define PGSQLCARRODAO_H

#include "carrodao.h"
#include "pgsqldaofactory.h"

#include <QtSql/QSqlTableModel>
#include <QVector>

class PGSQLCarroDAO : public CarroDAO, public PGSQLDAOFactory
{
private:
    QSqlTableModel *model;
    int nextVal();
public:
    PGSQLCarroDAO();
    bool salvar(Carro *carro);
    bool excluir(int id);
    QVector<Carro*> listarTodos();
    Carro *buscar(int id);

    QSqlTableModel *getModel();
};

#endif // PGSQLCARRODAO_H
