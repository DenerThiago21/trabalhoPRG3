#include "carro.h"

Carro::Carro()
{

}

int Carro::getCaroID() const
{
    return carroID;
}

void Carro::setCarroID(int value)
{
    carroID = value;
}

QString Carro::getTipo() const
{
    return tipo;
}

void Carro::setTipo(const QString &value)
{
    tipo = value;
}

QString Carro::getNome() const
{
    return nome;
}

void Carro::setNome(const QString &value)
{
    nome = value;
}

int Carro::getAno() const
{
    return ano;
}

void Carro::setAno(int value)
{
    ano = value;
}

QString Carro::getMarca() const
{
    return marca;
}

void Carro::setMarca(const QString &value)
{
    marca = value;
}


