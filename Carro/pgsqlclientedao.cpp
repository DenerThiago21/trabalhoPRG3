#include "pgsqlclientedao.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
#include <QtSql/QSqlQuery>
#include <QVariant>

int PGSQLClienteDAO::nextVal()
{
    QSqlDatabase db = getConexao();
    QSqlQuery query(db);

    query.exec("SELECT nextval('tb_cliente_seq') AS new_id");
    query.next();
    return query.value("new_id").toInt();
}

PGSQLClienteDAO::PGSQLClienteDAO()
{
    QSqlDatabase conexao = getConexao();
    model = new QSqlTableModel(0, conexao);

    model->setTable("tb_cliente");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "RG");
    model->setHeaderData(2, Qt::Horizontal, "CPF");
    model->setHeaderData(3, Qt::Horizontal, "Nome");
    model->setHeaderData(4, Qt::Horizontal, "DataNasc");
    model->setHeaderData(5, Qt::Horizontal, "Telefone1");
    model->setHeaderData(6, Qt::Horizontal, "telefone2");
    model->setHeaderData(7, Qt::Horizontal, "email");
}

bool PGSQLClienteDAO::salvar(Cliente *cliente)
{
    QSqlRecord registro = model->record();

    registro.setValue("clienteid", this->nextVal());
    registro.setValue("rg", cliente->getRG());
    registro.setValue("cpf", cliente->getCPF());
    registro.setValue("nome", cliente->getNome());
    registro.setValue("datanas", cliente->getDataNasc());
    registro.setValue("telefone1", cliente->getTelefone1());
    registro.setValue("telefone2", cliente->getTelefone2());
    registro.setValue("email", cliente->getEmail());

    model->insertRecord(-1, registro);
    return model->submitAll();
}

bool PGSQLClienteDAO::excluir(int id)
{
    bool removeu = false;
    for(int i = 0; i<model->rowCount() && !removeu; i++)
    {
        QSqlRecord registro = model->record(i);

        if(registro.value("clienteid").toInt() == id)
        {
            removeu = model->removeRow(i);
        }
    }
    return removeu;
}

QVector<Cliente *> PGSQLClienteDAO::listarTodos()
{
    QVector<Cliente*> listaCliente;

    model->select();

    for (int i = 0; i < model->rowCount(); i++) {
        QSqlRecord registro = model->record(i);
        Cliente *cliente = new Cliente();

        cliente->setClienteID(registro.value("clienteid").toInt());
        cliente->setRG(registro.value("rg").toString());
        cliente->setCPF(registro.value("cpf").toString());
        cliente->setNome(registro.value("nome").toString());
        cliente->setDataNasc(registro.value("datanas").toString());
        cliente->setTelefone1(registro.value("telefone1").toString());
        cliente->setTelefone2(registro.value("telefone2").toString());
        cliente->setEmail(registro.value("email").toString());
        listaCliente.append(cliente);
    }

    return listaCliente;
}

Cliente * PGSQLClienteDAO::buscar(int id)
{
    Cliente *cliente;
    for(int i = 0; i<model->rowCount(); i++)
    {
        QSqlRecord registro = model->record(i);

        if(registro.value("clienteid").toInt() == id)
        {
            cliente = new Cliente();
            cliente->setClienteID(registro.value("clienteid").toInt());
            cliente->setRG(registro.value("rg").toString());
            cliente->setCPF(registro.value("cpf").toString());
            cliente->setNome(registro.value("nome").toString());
            cliente->setDataNasc(registro.value("datanas").toString());
            cliente->setTelefone1(registro.value("telefone1").toString());
            cliente->setTelefone2(registro.value("telefone2").toString());
            cliente->setEmail(registro.value("email").toString());
        }
    }
    return cliente;
}

QSqlTableModel *PGSQLClienteDAO::getModel()
{
    return this->model;
}




