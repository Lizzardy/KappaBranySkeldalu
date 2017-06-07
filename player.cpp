#include "player.h"
#include <QPainter>
Player::Player()
{

}

QRectF Player::boundingRect() const
{
    return QRectF(0,0,150,200);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::red));
    painter->drawRect(boundingRect());
}
