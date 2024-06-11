#ifndef ROUTE_H
#define ROUTE_H

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class route :  public QGraphicsPixmapItem
{
public:
    route();
    //route(int id,qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    route(int id, QGraphicsItem *parent = nullptr);
    int getId() const;
private:
    int id;
};

#endif // ROUTE_H
