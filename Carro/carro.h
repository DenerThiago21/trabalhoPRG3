#ifndef CARRO_H
#define CARRO_H

#include <QString>

class Carro
{
public:
    Carro();
    int getCaroID() const;
    void setCarroID(int value);
    QString getTipo() const;
    void setTipo(const QString &value);
    QString getNome() const;
    void setNome(const QString &value);
    int getAno() const;
    void setAno(int value);
    QString getMarca() const;
    void setMarca(const QString &value);

private:
    int carroID;
    QString tipo;
    QString nome;
    int ano;
    QString marca;
};

#endif // CARRO_H
