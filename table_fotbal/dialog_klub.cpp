#include "dialog_klub.h"
#include "ui_dialog_klub.h"

Dialog_klub::Dialog_klub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_klub)
{
    ui->setupUi(this);
}

QString Dialog_klub::getNazev()
{
    return ui->lineNazev->text();
}

QString Dialog_klub::getLiga()
{
    return ui->comboLiga->currentText();
}

Dialog_klub::~Dialog_klub()
{
    delete ui;
}
