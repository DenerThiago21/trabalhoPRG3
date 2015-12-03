#ifndef CARROCONTROLLER_H
#define CARROCONTROLLER_H


#include <QtSql/QSqlTableModel>
#include "carro.h"
class CarroController
{
private:

public:
    CarroController();

    bool salvar(QString tipo, QString nome, int ano, QString marca);
    QVector<Carro*> listarTodos();
    QSqlTableModel *getModel();
};

#endif // CARROCONTROLLER_H
