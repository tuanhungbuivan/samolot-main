#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Samolot.h"
#include "Game.h"
#include <QApplication>
#include <QKeyEvent>
#include <QDialog>
#include <QTime>

extern Samolot * samolot;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //randomowa pozycja
    int random_number = rand() % 700;
    setPos(random_number,0);

    // wizualizacja samolotu
    QPixmap img("://kk/samolot1.png");
    QPixmap img2 = img.scaled(60,60, Qt::KeepAspectRatio);
    setPixmap(img2);
    setTransformOriginPoint(50,50);
    setRotation(180);

    // co jaki czas sie pojawia przeciwnik
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // zaczynanie czasu
    timer->start(50);
}
/*
void Enemy::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter){
        QApplication::quit();
    }
}
*/


void Enemy::move(){
    // poruszanie sie przeciwnika


    setPos(x(),y()+10);

    // znikanie przeciwnika na dole
    if (pos().y() > 600){
        //zmiejszanie zycia
        samolot->health->decrease();

        if(samolot->health->getHealth()==0){
            //printf("Koniec Gry");
            //keyPressEvent(*event)
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 300);
            QApplication::quit();

        }
        scene()->removeItem(this);
        delete this;
    }
}
