#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCadCliente_triggered();

    void on_actionCadCarro_triggered();

    void on_actionVenEfetuar_Vendas_triggered();

    void on_actionRelVendas_triggered();

    void on_actionPesqCliente_triggered();

    void on_actionPesqCarro_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
