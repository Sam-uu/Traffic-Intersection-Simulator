#include "feusignalisation.h"

#include <QGraphicsScene>
#include <unistd.h>
#include <QThread>


FeuSignalisation::FeuSignalisation(int id,qreal radius, QGraphicsItem *parent)
    : QGraphicsEllipseItem(-radius / 2, -radius / 2, radius, radius, parent), couleurActuelle(Qt::red),id(id)
{
    c1=0;
    c2=0;
    // Initialiser le timer
    timer = new QTimer(this);

    // Connecter le signal timeout du timer à la fonction changerCouleur
    connect(timer, SIGNAL(timeout()), this, SLOT(changerCouleur()));

    // Définir l'intervalle du timer à 20000 millisecondes (20 secondes)

    // Démarrer le timer
    timer->start();
    if(id==13 || id==23){
        couleurActuelle = Qt::green;
        timer->setInterval(15000);
        definirCouleur(couleurActuelle);
    }else if(id == 1 || id == 2){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }else if(id == 12 || id == 22){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(15000);
        definirCouleur(couleurActuelle);
    }

    if(id==33 || id==43){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }else if(id == 3 || id == 4){
        couleurActuelle = Qt::red;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }else if(id == 32 || id == 42){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(35000);
        definirCouleur(couleurActuelle);
    }
}

QColor FeuSignalisation::getcolor(){
    return couleurActuelle;
}

void FeuSignalisation::changerCouleur()
{

    if((id==13 || id==23) && couleurActuelle == Qt::green){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(25000);
        definirCouleur(couleurActuelle);
    }else if((id==13 || id==23) && couleurActuelle == Qt::darkGray){
        couleurActuelle = Qt::green;
        timer->setInterval(15000);
        definirCouleur(couleurActuelle);
    }
    if((id==1 || id==2) && couleurActuelle == Qt::darkGray){
        couleurActuelle = Qt::red;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }else if((id==1 || id==2) && couleurActuelle == Qt::red){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }
    if((id==12 || id==22) && c1 == 0){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(800);
        definirCouleur(couleurActuelle);
        c1++;
    }else if((id==12 || id==22) && couleurActuelle == Qt::darkGray && c1>0 && c1<=6){
        couleurActuelle = Qt::yellow;
        timer->setInterval(600);
        definirCouleur(couleurActuelle);
        c1++;
    }else if((id==12 || id==22) && couleurActuelle == Qt::yellow && c1>0 && c1<=6){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(800);
        definirCouleur(couleurActuelle);
        c1++;
    }else if((id==12 || id==22) && couleurActuelle == Qt::darkGray && c1 > 6){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(35000);
        definirCouleur(couleurActuelle);
        c1 = 0;
    }

    if((id==33 || id==43) && couleurActuelle == Qt::green){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(25000);
        definirCouleur(couleurActuelle);
    }else if((id==33 || id==43) && couleurActuelle == Qt::darkGray){
        couleurActuelle = Qt::green;
        timer->setInterval(15000);
        definirCouleur(couleurActuelle);
    }
    if((id==3 || id==4) && couleurActuelle == Qt::darkGray){
        couleurActuelle = Qt::red;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }else if((id==3 || id==4) && couleurActuelle == Qt::red){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
    }
    if((id==32 || id==42) && c2 == 0){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(800);
        definirCouleur(couleurActuelle);
        c2++;
    }else if((id==32 || id==42) && couleurActuelle == Qt::darkGray && c2>0 && c2<=6){
        couleurActuelle = Qt::yellow;
        timer->setInterval(600);
        definirCouleur(couleurActuelle);
        c2++;
    }else if((id==32 || id==42) && couleurActuelle == Qt::yellow && c2>0 && c2<=6){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(800);
        definirCouleur(couleurActuelle);
        c2++;
    }else if((id==32 || id==42) && couleurActuelle == Qt::darkGray && c2 > 6){
        couleurActuelle = Qt::darkGray;
        timer->setInterval(35000);
        definirCouleur(couleurActuelle);
        c2 = 0;
    }
}

void FeuSignalisation::modeclignotant(){
    // Clignoter le jaune pendant 10 secondes (5 clignotements)
    int c = 0;
    while(true){
        couleurActuelle = Qt::yellow;
        definirCouleur(couleurActuelle);
        QThread::msleep(800);  // Pause de 1 seconde
        c++;
        if(c==7){
            break;
        }
        couleurActuelle = Qt::black;
        definirCouleur(couleurActuelle);
        QThread::msleep(400);  // Pause de 1 seconde
        c++;
    }
}

void FeuSignalisation::definirCouleur(QColor couleur)
{
    // Définir la couleur du pinceau pour le cercle
    setBrush(QBrush(couleur));

    // Rafraîchir l'affichage
    update();
}


/*
void FeuSignalisation::changerCouleur()
{

    // Appliquer la nouvelle couleur
    definirCouleur(couleurActuelle);
    // Changer la couleur du feu
    if ((id == 1 || id == 2) && couleurActuelle == Qt::red)
    {
        couleurActuelle = Qt::black;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
        if(id == 13 || id == 23){
            couleurActuelle = Qt::green;
            // Appliquer la nouvelle
            timer->setInterval(15000);
            definirCouleur(couleurActuelle);
        }
    }
    else if (((id == 13 || id == 23) && (couleurActuelle == Qt::green)) || ((id == 12 || id == 22) && (couleurActuelle==Qt::black && c1<=6)))
    {
        if(id == 13 || id == 23){
            couleurActuelle = Qt::black;
            timer->setInterval(25000);
            definirCouleur(couleurActuelle);
        }
        if(id == 12 || id == 22){
            couleurActuelle = Qt::yellow;
            timer->setInterval(800);
            c1++;
            definirCouleur(couleurActuelle);
        }
    }else if((id == 12 || id == 22) && couleurActuelle==Qt::yellow && c1<=6){
        if(id == 12 || id == 22){
            couleurActuelle = Qt::black;
            timer->setInterval(600);
            c1++;
            definirCouleur(couleurActuelle);
        }
    }else if(c1>6){
        if(id == 12 || id == 22){
            couleurActuelle = Qt::black;
            timer->setInterval(35000);
            definirCouleur(couleurActuelle);
        }
        if(id == 1 || id == 2){
            couleurActuelle = Qt::red;
            timer->setInterval(20000);
            c1=0;
            definirCouleur(couleurActuelle);
        }
    }

    if ((id == 3 || id == 4) && couleurActuelle == Qt::red)
    {
        couleurActuelle = Qt::black;
        timer->setInterval(20000);
        definirCouleur(couleurActuelle);
        if(id == 33 || id == 43){
            couleurActuelle = Qt::green;
            // Appliquer la nouvelle
            timer->setInterval(15000);
            definirCouleur(couleurActuelle);
        }
    }
    else if (((id == 33 || id == 43) && (couleurActuelle == Qt::green)) || ((id == 32 || id == 42) && (couleurActuelle==Qt::black && c2<=6)))
    {
        if(id == 33 || id == 43){
            couleurActuelle = Qt::black;
            timer->setInterval(25000);
            definirCouleur(couleurActuelle);
        }
        if(id == 32 || id == 42){
            couleurActuelle = Qt::yellow;
            timer->setInterval(800);
            c2++;
            definirCouleur(couleurActuelle);
        }
    }else if((id == 32 || id == 42) && couleurActuelle==Qt::yellow && c2<=6){
        if(id == 32 || id == 42){
            couleurActuelle = Qt::black;
            timer->setInterval(600);
            c2++;
            definirCouleur(couleurActuelle);
        }
    }else if(c2>6){
        if(id == 32 || id == 42){
            couleurActuelle = Qt::black;
            timer->setInterval(35000);
            definirCouleur(couleurActuelle);
        }
        if(id == 3 || id == 4){
            couleurActuelle = Qt::red;
            timer->setInterval(20000);
            c2=0;
            definirCouleur(couleurActuelle);
        }
    }


}
*/
