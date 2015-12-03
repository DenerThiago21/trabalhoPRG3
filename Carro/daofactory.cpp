#include "daofactory.h"
#include "pgsqldaofactory.h"

int DAOFactory::PGSQL = 1;

DAOFactory::DAOFactory()
{

}

DAOFactory* DAOFactory::getDAOFactory(int factory)
{
    switch (factory)
    {
        case 1: {
            return new PGSQLDAOFactory();
            break;
        }
        default: {
            return NULL;
        }
    }
}
