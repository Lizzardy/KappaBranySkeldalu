#ifndef DIALOG_KLUB_H
#define DIALOG_KLUB_H

#include <QDialog>

namespace Ui {
class Dialog_klub;
}

class Dialog_klub : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_klub(QWidget *parent = 0);
    QString getNazev();
    QString getLiga();
    ~Dialog_klub();

private:
    Ui::Dialog_klub *ui;
};

#endif // DIALOG_KLUB_H
