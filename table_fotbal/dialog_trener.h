#ifndef DIALOG_TRENER_H
#define DIALOG_TRENER_H

#include <QDialog>

namespace Ui {
class Dialog_trener;
}

class Dialog_trener : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_trener(QWidget *parent = 0);
    QString getJmeno();
    int getVek();
    QString getFunkce();
    ~Dialog_trener();

private:
    Ui::Dialog_trener *ui;
};

#endif // DIALOG_TRENER_H
