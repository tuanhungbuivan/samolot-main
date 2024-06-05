#include "Health.h"
#include <QFont>
#include "Game.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // zycie
    health = 3;

    // wizualizacja zycia
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    //obnizenie pkt zycia
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
