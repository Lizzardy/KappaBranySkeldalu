#include "view.h"
#include <QDebug>


View::View()
{

}

View::View(QGraphicsScene *scene)
{
    setScene(scene);
    width = 1200;
    height = 800;

    this->scene()->addRect(0,0,width,height,
                           QPen(Qt::black),QBrush(QColor(100,100,100)));



    CreatePlayer();
    CreateEnemy();
    menuButtons();
    moveButtons();
    connect(button_left, SIGNAL(clicked(bool)), this, SLOT(handleButton()));



}

void View::handleButton()
{
    this->scene()->addRect(0,0,width,height,
                           QPen(Qt::black),QBrush(QColor(150,10,100)));

    qDebug()<< "booom";
}

void View::menuButtons()
{
    button_1 = new QPushButton("X", this);
    button_1->setGeometry(QRect(QPoint(width-1100, height-100),
        QSize(50, 50)));
    button_2 = new QPushButton("Kouzlo", this);
    button_2->setGeometry(QRect(QPoint(width-1050, height-100),
        QSize(50, 50)));
    button_3 = new QPushButton("obrana", this);
    button_3->setGeometry(QRect(QPoint(width-1100, height-50),
        QSize(50, 50)));
    button_4 = new QPushButton("ZZzz", this);
    button_4->setGeometry(QRect(QPoint(width-1150, height-100),
        QSize(50, 50)));
    button_5 = new QPushButton("útok", this);
    button_5->setGeometry(QRect(QPoint(width-1100, height-150),
                                QSize(50, 50)));
}

void View::moveButtons()
{
    button_left = new QPushButton("←", this);
    button_left->setGeometry(QRect(QPoint(width-500, height-5),
        QSize(50, 50)));
    button_right = new QPushButton("→", this);
    button_right->setGeometry(QRect(QPoint(width-400, height-5),
        QSize(50, 50)));
    button_go = new QPushButton("Vpřed", this);
    button_go->setGeometry(QRect(QPoint(width-450, height-5),
        QSize(50, 50)));

}

void View::CreatePlayer()
{
    player = new Player();
    this->scene()->addItem(player);
    player->setPos(width-1600 - player->boundingRect().width(),
                   height-500 - player->boundingRect().height());
}

void View::CreateEnemy()
{
    enemy = new Enemy();
    this->scene()->addItem(enemy);
    enemy->setPos(width-1250 - enemy->boundingRect().width(),
                   height-500 - enemy->boundingRect().height());
}

