#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog_klub.h"
#include "dialog_trener.h"
#include <QSqlQuery>
#include <QDebug>
#include <QItemSelectionModel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../table_fotbal/pokus.db");
    db.open();
    model_hrac = new QSqlTableModel(this);
    model_hrac->setTable("hraci");
    model_hrac->select();
    model_hrac->setHeaderData(1, Qt::Horizontal, "Jméno");
    model_hrac->setHeaderData(2, Qt::Horizontal, "Věk");
    model_hrac->setHeaderData(3, Qt::Horizontal, "Pozice");
    ui->tableView_hrac->setModel(model_hrac);
    ui->tableView_hrac->hideColumn(0);
    ui->tableView_hrac->hideColumn(4);
    ui->tableView_hrac->setSelectionBehavior(QAbstractItemView::SelectRows);

    model_klub = new QSqlTableModel(this);
    model_klub->setTable("klub");
    model_klub->select();
    ui->tableViewKlub->setModel(model_klub);
    ui->tableViewKlub->hideColumn(0);
    ui->tableViewKlub->hideColumn(3);
    ui->tableViewKlub->hideColumn(4);
    ui->tableViewKlub->setSelectionBehavior(QAbstractItemView::SelectRows);

    model_trener = new QSqlTableModel(this);
    model_trener->setTable("treneri");
    model_trener->select();
    ui->tableView_Trener->hideColumn(0);
    ui->tableView_Trener->hideColumn(4);
    ui->tableView_Trener->setModel(model_trener);
    ui->tableView_Trener->hideColumn(0);
    ui->tableView_Trener->hideColumn(4);
    ui->tableView_Trener->setSelectionBehavior(QAbstractItemView::SelectRows);



    aktualni_klub = -1;



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonPridatKlub_clicked()
{
    Dialog_klub d;
    if(d.exec() == QDialog::Accepted){

        QSqlQuery dotaz;
        dotaz.prepare("INSERT INTO klub VALUES(NULL, :nazev, :liga, NULL)");
        dotaz.bindValue(":nazev", d.getNazev());
        dotaz.bindValue(":liga", d.getLiga());
        dotaz.exec();
        model_klub->select();

    }
}

void MainWindow::on_buttonOdebratKlub_clicked()
{
    QItemSelectionModel *selection = ui->tableViewKlub->selectionModel();
    QString sql = "DELETE FROM klub WHERE id IN (";
    for(int i = 0; i<selection->selectedRows().count(); ++i)
    {
        QModelIndex index = selection->selectedRows().at(i);
        sql+= QString::number(model_klub->data(index).toInt());
        if(i+1 != selection->selectedRows().count())
        {
            sql+=", ";
        }
    }
    sql+=")";
    QSqlQuery dotaz;
    dotaz.prepare(sql);
    dotaz.exec();
    model_klub->select();
}


void MainWindow::on_buttonSoupiska_clicked()
{
    QItemSelectionModel *selection = ui->tableViewKlub->selectionModel();
    if(selection->selectedRows().count() == 0)
    {
        QMessageBox::warning(this, "Chyba", "Nevybral jsi žádný řádek");
        return;
    }
    aktualni_klub = model_klub->data(selection->selectedRows()[0]).toInt();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 1)
    {
        //Jsme na soupisce!
        if(aktualni_klub == -1)
        {
            QMessageBox::warning(this, "Chyba", "Nevybral jsi žádný řádek");
            ui->tabWidget->setCurrentIndex(0);
            return;
        }
        QSqlQuery dotaz;
        dotaz.prepare("SELECT * FROM klub WHERE id=:klub");
        dotaz.bindValue(":klub", aktualni_klub);
        dotaz.exec();
        if(!dotaz.next()) {
            QMessageBox::warning(this, "Chyba", "Nevybral jsi žádný řádek");
            ui->tabWidget->setCurrentIndex(0);
            return;
        }
        ui->label_nazevTymu->setText(dotaz.value("nazev").toString());
        ui->tableView_hrac->hideColumn(0);
        model_hrac->setFilter("id_klubu="+QString::number(aktualni_klub));
        model_trener->setFilter("id_klubu="+QString::number(aktualni_klub));
        model_hrac->select();
        model_trener->select();
    }
}

void MainWindow::on_hrac_pridat_clicked()
{
    Dialog d;
    if(d.exec() == QDialog::Accepted){

        QSqlQuery dotaz;
        dotaz.prepare("INSERT INTO hraci VALUES(NULL, :jmeno, :vek, :pozice, :id_klubu)");
        dotaz.bindValue(":jmeno", d.getJmeno());
        dotaz.bindValue(":vek", d.getVek());
        dotaz.bindValue(":pozice", d.getPost());
        dotaz.bindValue(":id_klubu", aktualni_klub);
        dotaz.exec();
        model_hrac->select();
        qDebug()<< d.getJmeno();


    }
}

void MainWindow::on_hrac_odebrat_clicked()
{
    QItemSelectionModel *selection = ui->tableView_hrac->selectionModel();
    QString sql = "DELETE FROM hraci WHERE id IN (";
    for(int i = 0; i<selection->selectedRows().count(); ++i)
    {
        QModelIndex index = selection->selectedRows().at(i);
        sql+= QString::number(model_hrac->data(index).toInt());
        if(i+1 != selection->selectedRows().count())
        {
            sql+=", ";
        }
    }
    sql+=")";
    QSqlQuery dotaz;
    dotaz.prepare(sql);
    dotaz.exec();
    model_hrac->select();
}


void MainWindow::on_trener_pridat_clicked()
{
    Dialog_trener d;
    if(d.exec() == QDialog::Accepted){

        QSqlQuery dotaz;
        dotaz.prepare("INSERT INTO treneri VALUES(NULL, :jmeno, :vek, :funkce, :id_klubu)");
        dotaz.bindValue(":jmeno", d.getJmeno());
        dotaz.bindValue(":vek", d.getVek());
        dotaz.bindValue(":funkce", d.getFunkce());
        dotaz.bindValue(":id_klubu", aktualni_klub);
        dotaz.exec();
        model_trener->select();
        qDebug()<< d.getJmeno();


    }
}

void MainWindow::on_trener_odebrat_clicked()
{
    QItemSelectionModel *selection = ui->tableView_Trener->selectionModel();
    QString sql = "DELETE FROM treneri WHERE id IN (";
    for(int i = 0; i<selection->selectedRows().count(); ++i)
    {
        QModelIndex index = selection->selectedRows().at(i);
        sql+= QString::number(model_trener->data(index).toInt());
        if(i+1 != selection->selectedRows().count())
        {
            sql+=", ";
        }
    }
    sql+=")";
    QSqlQuery dotaz;
    dotaz.prepare(sql);
    dotaz.exec();
    model_trener->select();
}


