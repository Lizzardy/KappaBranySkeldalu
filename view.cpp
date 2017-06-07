#include "view.h"


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


    button_1 = new QPushButton("1", this);
    button_1->setGeometry(QRect(QPoint(1000, 700),
        QSize(50, 50)));
    button_2 = new QPushButton("2", this);
    button_2->setGeometry(QRect(QPoint(1050, 700),
        QSize(50, 50)));
    button_3 = new QPushButton("3", this);
    button_3->setGeometry(QRect(QPoint(1000, 750),
        QSize(50, 50)));
    button_4 = new QPushButton("4", this);
    button_4->setGeometry(QRect(QPoint(950, 700),
        QSize(50, 50)));
    button_5 = new QPushButton("5", this);
    button_5->setGeometry(QRect(QPoint(1000, 650),
        QSize(50, 50)));

}

void View::handleButton()
{

}

void View::CreatePlayer()
{
    player = new Player();
    this->scene()->addItem(player);
    player->setPos(width/3 - player->boundingRect().width()/2,
                   height - player->boundingRect().height());
}
