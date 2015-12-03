#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente
{
public:
    Cliente();
    int getClienteID() const;
    void setClienteID(int value);
    QString getRG() const;
    void setRG(const QString &value);
    QString getCPF() const;
    void setCPF(const QString &value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getTelefone1() const;
    void setTelefone1(const QString &value);
    QString getTelefone2() const;
    void setTelefone2(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getDataNasc() const;
    void setDataNasc(const QString &value);

private:
    int clienteID;
    QString RG;
    QString CPF;
    QString nome;
    QString telefone1;
    QString telefone2;
    QString email;
    QString dataNasc;
};

#endif // CLIENTE_H
