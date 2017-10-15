#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

QString Dialog::getJmeno()
{
    return ui->lineJmeno->text();
}

int Dialog::getVek()
{
    return ui->spinBox->value();
}



QString Dialog::getPost()
{
    return ui->comboPost->currentText();
}

Dialog::~Dialog()
{
    delete ui;
}
