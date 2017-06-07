#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QPushButton>
#include "player.h"

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);
private:
    int width;
    int height;

    void handleButton();
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;

    Player *player;
    void CreatePlayer();
};

#endif // VIEW_H
