#include "Buttons.h"
#include <QGraphicsTextItem>
#include <QBrush>

Buttons::Buttons(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // narysowanie prostokatow
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // napis
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // pozwolenie na poruszanie/wybieranie myszka
    setAcceptHoverEvents(true);
}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Buttons::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // zmiana koloru
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Buttons::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // zmiana koloru
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
