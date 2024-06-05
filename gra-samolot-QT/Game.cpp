#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>
#include "Buttons.h"
#include "Samolot.h"
#include "Health.h"
#include <QString>


extern Samolot * samolot;

void Game::start()
{
    scene->clear();

    samolot = new Samolot();
    samolot->show();
}



Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/kk/bg.jpg")));
    //wizualizacja
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

}

void Game::displayMainMenu()
{
        //Wizualizacja tytulu gry
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Samoloty"));
        QFont titleFont("vol.1",50);
        titleText->setFont(titleFont);
        int txPos = this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos = 150;
        titleText->setPos(txPos,tyPos);
        scene->addItem(titleText);

        // stworzenie zagraj przycisk
        Buttons* playButton = new Buttons(QString("Zagraj"));
        int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
        int byPos = 275;
        playButton->setPos(bxPos,byPos);
        connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
        scene->addItem(playButton);

        // swtorzenie wyjdz przyciski
        Buttons* quitButton = new Buttons(QString("Wyjdz"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 350;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
}
/*
void Game::gameOver()
{
    QString m;
    m="lol";
    if(samolot->health==0) displayGameOverMenu(m);
}

void Game::displayGameOverMenu(QString textToDisplay)
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Koniec Gry"));
    QFont titleFont("vol.1",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // stworzenie zagraj przycisk
    Buttons* playButton = new Buttons(QString("Zagraj jeszcze raz"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // swtorzenie wyjdz przyciski
    Buttons* quitButton = new Buttons(QString("Wyjdz"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::restart()
{
    scene->clear();
    start();
}
*/

