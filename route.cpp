#include "route.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

route::route() {}

/*
route::route(int id, qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent), id(id)
{
    // Style the route
    setPen(QPen(Qt::darkGray, 3));
    setBrush(QBrush(Qt::lightGray));

    // Add white lines at the center
    qreal lineWidth = 10;
    QGraphicsLineItem *horizontalLine = new QGraphicsLineItem(x, y + height / 2 - lineWidth / 2, x + width, y + height / 2 - lineWidth / 2, this);
    QGraphicsLineItem *verticalLine = new QGraphicsLineItem(x + width / 2 - lineWidth / 2, y, x + width / 2 - lineWidth / 2, y + height, this);

    // Style the lines
    horizontalLine->setPen(QPen(Qt::white, 3));
    verticalLine->setPen(QPen(Qt::white, 3));
}*/

route::route(int id,QGraphicsItem *parent): QGraphicsPixmapItem(parent), id(id) {
    QPixmap image(":/route.png");
    setPixmap(image);

    // Ajuster la taille de l'image
    setScale(0.38);
}

route::getId() const{
    return id;
}
