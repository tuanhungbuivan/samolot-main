#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    //void displayGameOverMenu();
    //void delay();
protected:
    //virtual void keyPressEvent(QKeyEvent *event);

public slots:
    void move();
};


#endif // ENEMY_H
