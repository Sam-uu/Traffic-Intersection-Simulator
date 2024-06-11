#include "vehicule.h"

#include <QGraphicsItem>
#include "mywidget.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QPointF>
#include <cmath>



vehicule::vehicule(FeuSignalisation * f,int pd,int destination, int vitesseValue,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    QStringList carImages = {":/1.png",
                             ":/2.png",
                             ":/3.png",
                             ":/4.png",
                             ":/5.png"};

    // Select a random image path from the list
    QString randomImagePath = carImages.at(QRandomGenerator::global()->bounded(carImages.size()));

    // Load the image from the randomly selected path
    QPixmap image(randomImagePath);

    // Redimensionner l'image à la taille souhaitée
    QPixmap scaledImage = image.scaled(180, 180, Qt::KeepAspectRatio);

    // Définir l'image redimensionnée comme pixmap de l'élément graphique
    setPixmap(scaledImage);


    // Initialisez le QTimer
    timer = new QTimer(this);

    // Connectez le signal timeout du timer à la fonction move()
    connect(timer, &QTimer::timeout, this, [this, f,pd,destination]() { move(f,pd,destination); });

    // Définissez l'intervalle du timer à 30 millisecondes (réglage arbitraire)
    timer->setInterval(1000 / vitesseValue);
}

void vehicule::keyPressEvent(QKeyEvent * event)
{

    if(event->key() == Qt::Key_Left){
        setPos(x()-30,y());
    }

    if (event->key() == Qt::Key_Space)
    {
        // Commencez à déplacer l'objet lentement lorsqu'on presse la touche Espace
        timer->start();
    }

}



void vehicule::move(FeuSignalisation * f,int pd,int destination){
    qreal distance = std::abs(this->pos().x() - f->pos().x()) +
                     std::abs(this->pos().y() - f->pos().y());
    if(distance < 140){
        if(f->getcolor()==Qt::red){
        }else{
            switch(pd){
            case 1:
                if(destination==2){
                    setPos(x(),y()-1);
                }else if(destination==3){
                    if(this->pos().y()<350){
                        setRotation(90);
                        setPos(x()+1,y());
                    }else{
                        setPos(x(),y()-1);
                    }
                }else{
                    if(this->pos().y()<320){
                        setRotation(270);
                        setPos(x()-1,y());
                    }else{
                        setPos(x(),y()-1);
                    }
                }
                break;
            case 2:
                if(destination == 1){
                    setPos(x(),y()+1);
                }else if(destination==4){
                    if(this->pos().y()>320){
                        setRotation(270);
                        setPos(x()-1,y());
                    }else{
                        setPos(x(),y()+1);
                    }
                }else if(destination == 3){
                    if(this->pos().y()>370){
                        setRotation(90);
                        setPos(x()+1,y());
                    }else{
                        setPos(x(),y()+1);
                    }
                }
                break;
            case 3:
                if(destination == 4){
                    setPos(x()-1,y());
                }else if(destination==2){
                    if(this->pos().x()<480){
                        setRotation(0);
                        setPos(x(),y()-1);
                    }else{
                        setPos(x()-1,y());
                    }
                }else if(destination == 1){
                    if(this->pos().x()<430){
                        setRotation(180);
                        setPos(x(),y()+1);
                    }else{
                        setPos(x()-1,y());
                    }
                }
                break;
            case 4:
                if(destination == 3){
                    setPos(x()+1,y());
                }else if(destination==1){
                    if(this->pos().x()>350){
                        setPos(x(),y()+1);
                    }else{
                        setPos(x()+1,y());
                    }
                }else if(destination == 2){
                    if(this->pos().x()>460){
                        setPos(x(),y()-1);
                    }else{
                        setPos(x()+1,y());
                    }
                }
                break;
            }
        }
    }else{
        switch(pd){
        case 1:
            if(destination==2){
                setPos(x(),y()-1);
            }else if(destination==3){
                if(this->pos().y()<355){
                    if (rotation() < 90) {
                        setRotation(rotation() + 1);
                        setPos(x()+2,y());
                    }
                    setPos(x()+1,y());
                }else{
                    if(this->pos().y()<365){
                        if (rotation() < 60) {
                            setRotation(rotation() + 2);
                            setPos(x()+2,y()-1);
                        }
                    }
                    setPos(x(),y()-1);
                }
            }else if(destination==4){
                if(this->pos().y()<330){
                    if (rotation() > -90) {
                        setRotation(rotation() - 1);
                    }
                    setPos(x()-1,y());
                }else{
                    if(this->pos().y()<340){
                        if (rotation() > -60) {
                            setRotation(rotation() - 1);
                            setPos(x()-1,y()-1);
                        }
                    }
                    setPos(x(),y()-1);
                }
            }
            break;
        case 2:
            if(destination == 1){
                setPos(x(),y()+1);
            }else if(destination==4){
                if(this->pos().y()>330){
                    if (rotation() < 270) {
                        setRotation(rotation() + 1);
                        setPos(x()-2,y());
                    }
                    setPos(x()-1,y());
                }else{
                    if(this->pos().y()>325){
                        if (rotation() < 240) {
                            setRotation(rotation() + 2);
                            setPos(x()-2,y()+1);
                        }
                    }
                    setPos(x(),y()+1);
                }
            }else if(destination == 3){
                if(this->pos().y()>365){
                    if (rotation() > 90) {
                        setRotation(rotation() - 1);
                    }
                    setPos(x()+1,y());
                }else{
                    if(this->pos().y()>375){
                        if (rotation() > 60) {
                            setRotation(rotation() - 1);
                            setPos(x()+1,y()+1);
                        }
                    }
                    setPos(x(),y()+1);
                }
            }
            break;
        case 3:
            if(destination == 4){
                setPos(x()-1,y());
            }else if(destination==2){
                if(this->pos().x()<470){
                    if (rotation() < 360) {
                        setRotation(rotation() + 1);
                        setPos(x(),y()-2);
                    }
                    setPos(x(),y()-1);
                }else{
                    if(this->pos().x()<480){
                        if (rotation() < 330) {
                            setRotation(rotation() + 2);
                            setPos(x()-1,y()-1);
                        }
                    }
                    setPos(x()-1,y());
                }
            }else if(destination == 1){
                if(this->pos().x()<440){
                    if (rotation() > 180) {
                        setRotation(rotation() - 1);
                    }
                    setPos(x(),y()+1);
                }else{
                    if(this->pos().x()<450){
                        if (rotation() > 240) {
                            setRotation(rotation() - 2);
                            setPos(x()-1,y()-1);
                        }
                    }
                    setPos(x()-1,y());
                }
            }
            break;
        case 4:
            if(destination == 3){
                setPos(x()+1,y());
            }else if(destination==1){
                if(this->pos().x()>440){
                    if (rotation() < 180) {
                        setRotation(rotation() + 1);
                        setPos(x(),y()+2);
                    }
                    setPos(x(),y()+1);
                }else{
                    if(this->pos().x()>430){
                        if (rotation() < 150) {
                            setRotation(rotation() + 2);
                            setPos(x()+1,y()+1);
                        }
                    }
                    setPos(x()+1,y());
                }
            }else if(destination == 2){
                if(this->pos().x()>460){
                    if (rotation() > 0) {
                        setRotation(rotation() - 1);
                    }
                    setPos(x(),y()-1);
                }else{
                    if(this->pos().x()>450){
                        if (rotation() > 60) {
                            setRotation(rotation() - 2);
                            setPos(x()+1,y()+1);
                        }
                    }
                    setPos(x()+1,y());
                }
            }
            break;
        }
    }
}

// Dans la définition de la fonction move de la classe Vehicule (vehicule.cpp)
/*void vehicule::move(FeuSignalisation * f) {

    // Obtenez la position actuelle du véhicule
    QPointF positionVehicule = this->pos();
    // Ajoutez votre logique pour déplacer le véhicule
    setPos(positionVehicule.x(), positionVehicule.y() - 1);

    // Parcourez vos feux de signalisation et vérifiez s'il y en a un à côté du véhicule
    for (int i = 0; i < 4; ++i) {
        QPointF positionFeu = f->pos();

        // Ajoutez votre logique pour vérifier si le feu est à côté du véhicule
        if (QPointF(positionVehicule - positionFeu).manhattanLength()<50) {
            if (f->getcolor() == Qt::red) {
                // Le feu est rouge, le véhicule s'arrête
                // Ajoutez votre logique pour arrêter le véhicule
                return;
            }
            // Le feu est vert, le véhicule peut continuer
        }
    }

    // Ajoutez votre logique pour déplacer le véhicule
    setPos(positionVehicule.x(), positionVehicule.y() - 1);

    // Ajoutez votre logique pour arrêter le véhicule si nécessaire
    if (positionVehicule.y() <= 0) {
        timer->stop();
    }
}*/
