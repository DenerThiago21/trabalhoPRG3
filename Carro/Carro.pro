#-------------------------------------------------
#
# Project created by QtCreator 2015-11-22T13:44:25
#
#-------------------------------------------------

QT += core
QT += sql
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Carro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frmcadclientedialog.cpp \
    frmcadcarrodialog.cpp \
    frmvendadialog.cpp \
    frmpesqclientedialog.cpp \
    frmpesqcarrodialog.cpp \
    carro.cpp \
    cliente.cpp \
    compra.cpp \
    frmrelvendadialog.cpp \
    carrocontroller.cpp \
    clientecontroller.cpp \
    compracontroller.cpp \
    daofactory.cpp \
    carrodao.cpp \
    clientedao.cpp \
    compradao.cpp \
    pgsqldaofactory.cpp \
    pgsqlcarrodao.cpp \
    pgsqlclientedao.cpp \
    pgsqlcompradao.cpp

HEADERS  += mainwindow.h \
    frmcadclientedialog.h \
    frmcadcarrodialog.h \
    frmvendadialog.h \
    frmpesqclientedialog.h \
    frmpesqcarrodialog.h \
    carro.h \
    cliente.h \
    compra.h \
    frmrelvendadialog.h \
    carrocontroller.h \
    clientecontroller.h \
    compracontroller.h \
    daofactory.h \
    carrodao.h \
    clientedao.h \
    compradao.h \
    pgsqldaofactory.h \
    pgsqlcarrodao.h \
    pgsqlclientedao.h \
    pgsqlcompradao.h

FORMS    += mainwindow.ui \
    frmcadclientedialog.ui \
    frmcadcarrodialog.ui \
    frmvendadialog.ui \
    frmpesqclientedialog.ui \
    frmpesqcarrodialog.ui \
    frmrelvendadialog.ui
