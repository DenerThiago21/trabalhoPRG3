#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frmcadcarrodialog.h"
#include "frmcadclientedialog.h"
#include "frmpesqcarrodialog.h"
#include "frmpesqclientedialog.h"
#include "frmrelvendadialog.h"
#include "frmvendadialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCadCliente_triggered()
{
    FrmCadClienteDialog *frmCadClienteDialog = new FrmCadClienteDialog();
    frmCadClienteDialog->exec();
}

void MainWindow::on_actionCadCarro_triggered()
{
    FrmCadCarroDialog *frmCadCarroDialog = new FrmCadCarroDialog();
    frmCadCarroDialog->exec();
}

void MainWindow::on_actionVenEfetuar_Vendas_triggered()
{
    FrmVendaDialog *frmVendaDialog = new FrmVendaDialog();
    frmVendaDialog->exec();
}

void MainWindow::on_actionRelVendas_triggered()
{
    FrmRelVendaDialog *frmRelVendaDialog = new FrmRelVendaDialog();
    frmRelVendaDialog->exec();
}

void MainWindow::on_actionPesqCliente_triggered()
{
    FrmPesqClienteDialog *frmPesqClienteDialog = new FrmPesqClienteDialog();
    frmPesqClienteDialog->exec();
}

void MainWindow::on_actionPesqCarro_triggered()
{
    FrmPesqCarroDialog *frmPesqCarroDialog = new FrmPesqCarroDialog();
    frmPesqCarroDialog->exec();
}
