#ifndef RELVENDADIALOG_H
#define RELVENDADIALOG_H

#include <QDialog>

namespace Ui {
class RelVendaDialog;
}

class RelVendaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RelVendaDialog(QWidget *parent = 0);
    ~RelVendaDialog();

private:
    Ui::RelVendaDialog *ui;
};

#endif // RELVENDADIALOG_H
