#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>
#include "Buttons.h"
#include "Samolot.h"

extern Samolot *samolot;

Samolot::Samolot(QWidget *parent){
    // tworzenie sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/kk/bg.jpg")));
    //wizualizacja
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // tworzenie gracza
    player = new Player();
    player->setPos(400,500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // dodanie gracza
    scene->addItem(player);

    // punkty/życie
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // pojawienie się przeciwnika
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
