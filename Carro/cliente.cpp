#include "cliente.h"

Cliente::Cliente()
{

}

int Cliente::getClienteID() const
{
    return clienteID;
}

void Cliente::setClienteID(int value)
{
    clienteID = value;
}

QString Cliente::getRG() const
{
    return RG;
}

void Cliente::setRG(const QString &value)
{
    RG = value;
}

QString Cliente::getCPF() const
{
    return CPF;
}

void Cliente::setCPF(const QString &value)
{
    CPF =  value;
}

QString Cliente::getNome() const
{
    return nome;
}

void Cliente::setNome(const QString &value)
{
    nome = value;
}

QString Cliente::getTelefone1() const
{
    return telefone1;
}

void Cliente::setTelefone1(const QString &value)
{
    telefone1 = value;
}

QString Cliente::getTelefone2() const
{
    return telefone2;
}

void Cliente::setTelefone2(const QString &value)
{
    telefone2 = value;
}

QString Cliente::getEmail() const
{
    return email;
}

void Cliente::setEmail(const QString &value)
{
    email = value;
}

QString Cliente::getDataNasc() const
{
    return dataNasc;
}

void Cliente::setDataNasc(const QString &value)
{
    dataNasc = value;
}

