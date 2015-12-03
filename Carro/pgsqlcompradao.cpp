#include "pgsqlcompradao.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
#include <QtSql/QSqlQuery>
#include <QVariant>

int PGSQLCompraDAO::nextVal()
{
    QSqlDatabase db = getConexao();
    QSqlQuery query(db);

    query.exec("SELECT nextval('tb_compra_seq') AS new_id");
    query.next();
    return query.value("new_id").toInt();
}

PGSQLCompraDAO::PGSQLCompraDAO()
{
    QSqlDatabase conexao = getConexao();
    model = new QSqlTableModel(0, conexao);

    model->setTable("tb_compra");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "FormaPagamento");
    model->setHeaderData(2, Qt::Horizontal, "ValorTotal");
}

bool PGSQLCompraDAO::salvar(Compra *compra)
{
    QSqlRecord registro = model->record();

    registro.setValue("compraid", this->nextVal());
    registro.setValue("forma_pagamento", compra->getFormaPagamento());
    registro.setValue("valor_total", compra->getValorTotal());
    registro.setValue("clienteid", compra->getCliente()->getClienteID());
    registro.setValue("carroid", compra->getCarro()->getCaroID());

    model->insertRecord(-1, registro);
    return model->submitAll();
}

QVector<Compra *> PGSQLCompraDAO::listarTodos()
{
     QVector<Compra*> listaCompra;

    model->select();

    for(int i = 0; i<model->rowCount(); i++)
    {
        QSqlRecord registro = model->record(i);
        Compra *compra = new Compra();

        compra->setCompraID(registro.value("compraid").toInt());
        compra->setFormaPagamento(registro.value("forma_pagamento").toString());
        compra->setValorTotal(registro.value("valor_total").toString());


        compra->setCarro(DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->buscar(registro.value("carroid").toInt()));
        compra->setCliente(DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->buscar(registro.value("clienteid").toInt()));

        listaCompra.append(compra);
    }
    return listaCompra;
}


//bool PGSQLCompraDAO::listarTodos()
//{

//    QSqlDatabase db = getConexao();
//    QSqlQuery query(db);

//    query.prepare("select c.compraid, c.forma_pagamento, c.valor_total,"
//                  "cli.clienteid, cli.nome, cli.rg, cli.cpf,"
//                  "car.carroid, car.nome, car.marca"
//                  "from tb_compra c "
//                  "inner join tb_cliente cli on c.clienteid = cli.clienteid"
//                  "inner join tb_carro car on c.carroid = car.carroid");

//     return query.exec();
//}
