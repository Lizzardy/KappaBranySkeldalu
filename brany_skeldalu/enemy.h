#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>

class Enemy : public QGraphicsItem
{
public:
    Enemy();
    QRectF boundingRect() const;
protected:
    //znazornuje tvar objektu, sluzi na detekcii kolizii
    QPainterPath shape() const;
    //povinna metoda, tu se vykresluje objekt
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:

};

#endif // PLAYER_H
