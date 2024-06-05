#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QString>
#include "Health.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:

    Game(QWidget * parent=0);
    void displayMainMenu();
    //void displayGameOverMenu(QString textToDisplay);
    //void gameOver();
    QGraphicsScene * scene;


public slots:
    void start();
    //void restart();
};

#endif // GAME_H
