#include "enemy.h"
#include <QPainter>
Enemy::Enemy()
{

}

QRectF Enemy::boundingRect() const
{
    int width = 250;
    int height = 300;
    return QRectF(0,0,width,height);
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    return path;
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(QBrush(Qt::red));
//    painter->drawRect(boundingRect());
    QImage image("../brany_skeldalu/img/enemy.jpg");
    painter->drawImage(QPoint(0,0),image/*.scaled(80,80)*/);
}//236x370
