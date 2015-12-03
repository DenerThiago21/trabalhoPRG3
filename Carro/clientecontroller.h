#ifndef CLIENTECONTROLLER_H
#define CLIENTECONTROLLER_H

#include <QtSql/QSqlTableModel>
#include "cliente.h"
class ClienteController
{
private:

public:
    ClienteController();

    bool salvar(QString RG, QString CPF, QString nome,QString telefone1, QString telefone2, QString email, QString dataNasc);
    QVector<Cliente*> listarTodos();
    QSqlTableModel *getModel();
};

#endif // CLIENTECONTROLLER_H
