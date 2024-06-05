#include "Bullets.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Samolot.h"


Samolot *samolot;

Bullets::Bullets(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent){
    // obraz strzalow
    QPixmap img("://kk/bullet5.png");
    QPixmap img2 = img.scaled(25,25, Qt::KeepAspectRatio);
    setPixmap(img2);


    //polaczenie
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullets::move()
{
    // zabijanie
    QList<QGraphicsItem *> colliding_item = collidingItems();

    for(int i=0, n=colliding_item.size();i<n;++i){
        if (typeid(*(colliding_item[i])) == typeid(Enemy)){
            //dodawanie pkt
            samolot->score->increase();
            //usuwanie strzalow i przeciwnikow
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;

            return;
        }
    }

    // poruszaenie sie strzalow
    setPos(x(),y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
