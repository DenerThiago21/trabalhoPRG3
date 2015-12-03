#include "frmcadcarrodialog.h"
#include "ui_frmcadcarrodialog.h"
#include <QMessageBox>
#include "carrocontroller.h"

FrmCadCarroDialog::FrmCadCarroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmCadCarroDialog)
{
    ui->setupUi(this);
}

FrmCadCarroDialog::~FrmCadCarroDialog()
{
    delete ui;
}

void FrmCadCarroDialog::on_btCancelar_clicked()
{
    this->close();
}

void FrmCadCarroDialog::on_btGravar_clicked()
{

    QString nome = ui->edNome->text();
    QString marca = ui->edMarca->text();
    QString tipo = ui->edTipo->text();
    int ano = ui->edAno->text().toInt();

    QMessageBox confirm;
    QMessageBox msgShow;

    confirm.setText("Você deseja realmente cadastrar o Carro?");
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    int ret = confirm.exec();

    switch(ret) {
        case QMessageBox::Yes : {
            if (carroController->salvar(tipo, nome, ano, marca)) {
                msgShow.setText("Carro salvo com sucesso!");
                this->close();
            } else {
                msgShow.setText("O Carro não foi salvo");
            }
            msgShow.exec();
            break;
        }
        case QMessageBox::No : {
            this->close();
            break;
        }
    }
}

void FrmCadCarroDialog::on_btLimpar_clicked()
{
    ui->edAno->setText("");
    ui->edMarca->setText("");
    ui->edNome->setText("");
    ui->edTipo->setText("");
}
