#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //pkt zaczynanie od 0
    score = 0;
    //wizualizacja pkt
    setPlainText(QString("Punkty: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    //dodawanie pkt
    score++;
    setPlainText(QString("Punkty: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
