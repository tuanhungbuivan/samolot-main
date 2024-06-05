#ifndef SAMOLOT_H
#define SAMOLOT_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Buttons.h"
#include "Game.h"

class Samolot: public QGraphicsView{
    Q_OBJECT
public:
    Samolot(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Samolot * game;

};

#endif  // SAMOLOT_H
