#ifndef BULLETS_H
#define BULLETS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Bullets: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullets(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLETS_H
