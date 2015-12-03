#include "clientecontroller.h"
#include "daofactory.h"

ClienteController::ClienteController()
{

}

bool ClienteController::salvar(QString RG, QString CPF, QString nome, QString telefone1, QString telefone2, QString email, QString dataNasc)
{
    Cliente *cliente = new Cliente();
    cliente->setRG(RG);
    cliente->setCPF(CPF);
    cliente->setNome(nome);
    cliente->setTelefone1(telefone1);
    cliente->setTelefone2(telefone2);
    cliente->setEmail(email);
    cliente->setDataNasc(dataNasc);

    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->salvar(cliente);
}

QVector<Cliente *> ClienteController::listarTodos()
{
    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->listarTodos();
}

QSqlTableModel *ClienteController::getModel()
{
    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getClienteDAO()->getModel();
}


