#include "pgsqlcarrodao.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
#include <QtSql/QSqlQuery>
#include <QVariant>

int PGSQLCarroDAO::nextVal()
{
    QSqlDatabase db = getConexao();
    QSqlQuery query(db);

    query.exec("SELECT nextval('tb_carro_seq') AS new_id");
    query.next();
    return query.value("new_id").toInt();
}

PGSQLCarroDAO::PGSQLCarroDAO()
{
    QSqlDatabase conexao = getConexao();
    model = new QSqlTableModel(0, conexao);

    model->setTable("tb_carro");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nome");
    model->setHeaderData(2, Qt::Horizontal, "Ano");
    model->setHeaderData(3, Qt::Horizontal, "Marca");
    model->setHeaderData(4, Qt::Horizontal, "Tipo");
}

bool PGSQLCarroDAO::salvar(Carro *carro)
{
    QSqlRecord registro = model->record();

    registro.setValue("carroid", this->nextVal());
    registro.setValue("nome", carro->getNome());
    registro.setValue("ano", carro->getAno());
    registro.setValue("marca", carro->getMarca());
    registro.setValue("tipo", carro->getTipo());

    model->insertRecord(-1, registro);
    return model->submitAll();
}

bool PGSQLCarroDAO::excluir(int id)
{
    bool removeu = false;
    for(int i = 0; i<model->rowCount() &&  !removeu; i++)
    {
        QSqlRecord registro = model->record(i);

        if(registro.value("carroid").toInt() == id)
        {
            removeu = model->removeRow(i);
        }
    }
    return removeu;
}

QVector<Carro *> PGSQLCarroDAO::listarTodos()
{
    QVector<Carro*> listaCarro;

    model->select();

    for (int i = 0; i < model->rowCount(); i++) {
        QSqlRecord registro = model->record(i);
        Carro *carro= new Carro();

        carro->setCarroID(registro.value("carroid").toInt());
        carro->setNome(registro.value("nome").toString());
        carro->setAno(registro.value("ano").toInt());
        carro->setMarca(registro.value("marca").toString());
        carro->setTipo(registro.value("tipo").toString());
        listaCarro.append(carro);
    }

    return listaCarro;
}

Carro * PGSQLCarroDAO::buscar(int id)
{
    Carro *carro;
    for(int i = 0; i<model->rowCount(); i++)
    {
        QSqlRecord registro = model->record(i);

        if(registro.value("carroid").toInt() == id)
        {
            carro = new Carro();
            carro->setCarroID(registro.value("carroid").toInt());
            carro->setNome(registro.value("nome").toString());
            carro->setAno(registro.value("ano").toInt());
            carro->setMarca(registro.value("marca").toString());
            carro->setTipo(registro.value("tipo").toString());
        }
    }
    return carro;
}

QSqlTableModel *PGSQLCarroDAO::getModel()
{
    return this->model;
}

