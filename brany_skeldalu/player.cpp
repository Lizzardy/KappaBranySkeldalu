#include "player.h"
#include <QPainter>
Player::Player()
{

}

QRectF Player::boundingRect() const
{
    int width = 250;
    int height = 300;
    return QRectF(0,0,width,height);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(QBrush(Qt::red));
//    painter->drawRect(boundingRect());
    QImage image("R:/soukrome/PRO III/brany_skeldalu/img/character_1.png");
    painter->drawImage(QPoint(0,0),image/*.scaled(80,80)*/);
}
