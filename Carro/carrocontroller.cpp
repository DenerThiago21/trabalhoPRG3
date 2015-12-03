#include "carrocontroller.h"
#include "daofactory.h"
#include <QVector>

CarroController::CarroController()
{

}

bool CarroController::salvar(QString tipo, QString nome, int ano, QString marca)
{
    Carro *carro = new Carro();
    carro->setTipo(tipo);
    carro->setNome(nome);
    carro->setAno(ano);
    carro->setMarca(marca);

    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->salvar(carro);
}

QVector<Carro*> CarroController::listarTodos()
{
    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->listarTodos();
}


QSqlTableModel *CarroController::getModel()
{
    return DAOFactory::getDAOFactory(DAOFactory::PGSQL)->getCarroDAO()->getModel();
}

