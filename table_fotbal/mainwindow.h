#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>


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
    void on_hrac_pridat_clicked();

    void on_hrac_odebrat_clicked();

    void on_buttonPridatKlub_clicked();

    void on_buttonOdebratKlub_clicked();



    void on_tabWidget_currentChanged(int index);

    void on_buttonSoupiska_clicked();

    void on_trener_pridat_clicked();

    void on_trener_odebrat_clicked();



private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model_hrac;
    QSqlTableModel *model_klub;
    QSqlTableModel *model_trener;
    int aktualni_klub;


};

#endif // MAINWINDOW_H
