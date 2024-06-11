#ifndef VEHICULE_H
#define VEHICULE_H

#include "feusignalisation.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QTime>

class vehicule: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    vehicule(FeuSignalisation *f, int pd, int destination, int vitesseValue, QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void move(FeuSignalisation * f,int pd,int destination);
private:
    QTimer *timer;
    bool stopped;
    QTime stopTime;
    int waitingTime;
};

#endif // VEHICULE_H
