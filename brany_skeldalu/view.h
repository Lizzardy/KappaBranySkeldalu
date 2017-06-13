#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QPushButton>
#include "player.h"
#include "enemy.h"

class View : public QGraphicsView
{
     Q_OBJECT

public:
    View();
    View(QGraphicsScene *scene);
public slots:
    void handleButton();

private:
    int width;
    int height;


    void menuButtons();
    void moveButtons();

    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;

    QPushButton *button_left;
    QPushButton *button_right;
    QPushButton *button_go;

    Player *player;
    Enemy *enemy;
    void CreatePlayer();
    void CreateEnemy();
};

#endif // VIEW_H
