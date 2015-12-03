#include "frmcadclientedialog.h"
#include "ui_frmcadclientedialog.h"
#include <QMessageBox>

FrmCadClienteDialog::FrmCadClienteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmCadClienteDialog)
{
    ui->setupUi(this);
    ui->edRG->setInputMask("0.000.000");
    ui->edCPF->setInputMask("000.000.000-00");
    ui->edNasc->setInputMask("00/00/0000");
    ui->edTelefone1->setInputMask("(00)0000-0000");
    ui->edTelefone2->setInputMask("(00)0000-0000");
}

FrmCadClienteDialog::~FrmCadClienteDialog()
{
    delete ui;
}


void FrmCadClienteDialog::on_btCancelar_clicked()
{
    this->close();
}

void FrmCadClienteDialog::on_btGravar_clicked()
{
    QString nome = ui->edNome->text();
    QString RG = ui->edRG->text();
    QString CPF = ui->edCPF->text();
    QString telefone1 = ui->edTelefone1->text();
    QString telefone2 = ui->edTelefone2->text();
    QString email = ui->edEmail->text();
    QString dataNasc = ui->edNasc->text();

    QMessageBox confirm;
    QMessageBox msgShow;

    confirm.setText("Você deseja realmente cadastrar o Cliente?");
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    int ret = confirm.exec();

    switch(ret) {
        case QMessageBox::Yes : {
            if (clienteController->salvar(RG, CPF, nome, telefone1, telefone2, email, dataNasc)) {
                msgShow.setText("Cliente salvo com sucesso!");
                this->close();
            } else {
                msgShow.setText("O Cliente não foi salvo");
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

void FrmCadClienteDialog::on_btLimpar_clicked()
{
    ui->edCPF->setText("");
    ui->edEmail->setText("");
    ui->edNasc->setText("");
    ui->edNome->setText("");
    ui->edRG->setText("");
    ui->edTelefone1->setText("");
    ui->edTelefone2->setText("");
}
