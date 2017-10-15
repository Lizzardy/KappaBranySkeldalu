#include "dialog_trener.h"
#include "ui_dialog_trener.h"

Dialog_trener::Dialog_trener(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_trener)
{
    ui->setupUi(this);
}

QString Dialog_trener::getJmeno()
{
    return ui->lineJmeno->text();
}

int Dialog_trener::getVek()
{
    return ui->spinVek->value();
}

QString Dialog_trener::getFunkce()
{
    return ui->comboFunkce->currentText();
}

Dialog_trener::~Dialog_trener()
{
    delete ui;
}
