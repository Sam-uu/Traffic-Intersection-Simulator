#ifndef FEUSIGNALISATION_H
#define FEUSIGNALISATION_H

#include <QGraphicsEllipseItem>
#include <QWidget>
#include <QTimer>
#include <QBrush>
#include <QObject>
#include <QPainter>

class FeuSignalisation : public QObject , public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    FeuSignalisation(int id,qreal radius, QGraphicsItem *parent = nullptr);
    void modeclignotant();

public slots:
    void changerCouleur();
    QColor getcolor();


private:
    QTimer *timer;
    QColor couleurActuelle;
    int c1;
    int c2;
    int id;

    // Méthode pour définir la couleur du feu
    void definirCouleur(QColor couleur);
};

#endif // FEUSIGNALISATION_H
