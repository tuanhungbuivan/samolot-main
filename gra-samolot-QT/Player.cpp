#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullets.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){
    //wizualicja gracza / samolotu
    QPixmap img("://kk/samolot3.png");
    QPixmap img2 = img.scaled(100,100, Qt::KeepAspectRatio);
    setPixmap(img2);
}


void Player::keyPressEvent(QKeyEvent * event){
    //poruszanie sie strzalkami /strzelanie spacja
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() +100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        Bullets * bullets = new Bullets();
        bullets->setPos(x(),y());
        scene()->addItem(bullets);
    }
}

void Player::spawn()
{
    //stworzenie przeciwnika
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
