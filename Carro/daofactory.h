#ifndef DAOFACTORY_H
#define DAOFACTORY_H

#include "compradao.h"
#include "clientedao.h"
#include "carrodao.h"

class DAOFactory
{
public:
    DAOFactory();
    static int PGSQL;
    static DAOFactory *getDAOFactory(int factory);

    virtual ClienteDAO *getClienteDAO() = 0;
    virtual CompraDAO *getCompraDAO() = 0;
    virtual CarroDAO *getCarroDAO() = 0;
};

#endif // DAOFACTORY_H
