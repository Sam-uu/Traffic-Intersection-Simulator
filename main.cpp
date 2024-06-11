#include "mainwindow.h"
#include "mywidget.h"


#include <QApplication>
#include "vehicule.h"
#include "route.h"
#include "feusignalisation.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QPainterPath>

#include <QPushButton>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create scene
    QGraphicsScene * scene=new QGraphicsScene();

    QGraphicsView * view=new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);

    view->setFixedSize(855, 683);
    view->setSceneRect(0,0,853,680);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //create road
    route * r= new route(1);

    scene->addItem(r);


    QPainterPath rec1;
    rec1.addRoundedRect(0, 0, 45, 90, 8, 8);
    QPainterPath rec2;
    rec2.addRoundedRect(0, 0, 90, 45, 8, 8);

    QGraphicsPathItem *rect1 = new QGraphicsPathItem(rec1);
    QGraphicsPathItem *rect2 = new QGraphicsPathItem(rec1);
    QGraphicsPathItem *rect3 = new QGraphicsPathItem(rec2);
    QGraphicsPathItem *rect4 = new QGraphicsPathItem(rec2);

    // Customize the appearance of the rectangle
    rect1->setBrush(QBrush(Qt::black));  // Set the border color
    rect2->setBrush(QBrush(Qt::black));
    rect3->setBrush(QBrush(Qt::black));
    rect4->setBrush(QBrush(Qt::black));

    //create feu de signalisation
    FeuSignalisation * f1=new FeuSignalisation(1,20);
    FeuSignalisation * f2=new FeuSignalisation(2,20);
    FeuSignalisation * f3=new FeuSignalisation(3,20);
    FeuSignalisation * f4=new FeuSignalisation(4,20);

    FeuSignalisation * f12=new FeuSignalisation(12,20);
    FeuSignalisation * f22=new FeuSignalisation(22,20);
    FeuSignalisation * f32=new FeuSignalisation(32,20);
    FeuSignalisation * f42=new FeuSignalisation(42,20);

    FeuSignalisation * f13=new FeuSignalisation(13,20);
    FeuSignalisation * f23=new FeuSignalisation(23,20);
    FeuSignalisation * f33=new FeuSignalisation(33,20);
    FeuSignalisation * f43=new FeuSignalisation(43,20);

    for (int i = 0; i < 10; ++i) {
        QGraphicsRectItem *stripe1 = new QGraphicsRectItem(0, 0, 10, 5);
        QGraphicsRectItem *stripe2 = new QGraphicsRectItem(0, 0, 10, 5);
        stripe1->setPos(i * 10 + 469, 550);
        stripe2->setPos(i * 10 + 343, 130);
        stripe1->setBrush(Qt::white);
        stripe2->setBrush(Qt::white);
        scene->addItem(stripe1);
        scene->addItem(stripe2);
    }

    for (int i = 0; i < 10; ++i) {
        QGraphicsRectItem *stripe3 = new QGraphicsRectItem(0, 0, 5, 10);
        QGraphicsRectItem *stripe4 = new QGraphicsRectItem(0, 0, 5, 10);
        stripe3->setPos(670, i * 10 + 229);
        stripe4->setPos(250, i * 10 + 355);
        stripe3->setBrush(Qt::white);
        stripe4->setBrush(Qt::white);
        scene->addItem(stripe3);
        scene->addItem(stripe4);
    }

    //add item to the scene


    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);
    scene->addItem(rect4);

    scene->addItem(f1);
    scene->addItem(f2);
    scene->addItem(f3);
    scene->addItem(f4);

    scene->addItem(f12);
    scene->addItem(f22);
    scene->addItem(f32);
    scene->addItem(f42);

    scene->addItem(f13);
    scene->addItem(f23);
    scene->addItem(f33);
    scene->addItem(f43);/*

    int stripeWidth = 10;  // Adjust the width of each stripe as needed
    int totalStripes = view->height() / 65 ;

    for (int i = 0; i < totalStripes; ++i) {
        QGraphicsRectItem *stripe = new QGraphicsRectItem(0, 0, 5, stripeWidth);
        stripe->setPos(view->width() / 2+180, i * stripeWidth + 230);  // Adjust the position as needed
        stripe->setBrush(Qt::white);
        scene->addItem(stripe);
    }

    for (int i = 0; i < totalStripes; ++i) {
        QGraphicsRectItem *stripe = new QGraphicsRectItem(0, 0, 5, stripeWidth);
        stripe->setPos(view->width() / 2-125, i * stripeWidth + 352);  // Adjust the position as needed
        stripe->setBrush(Qt::white);
        scene->addItem(stripe);
    }

    int stripeHeight = 10;  // Adjust the width of each stripe as needed
    int TotalStripes = view->width() / 80 ;

    for (int i = 0; i < TotalStripes; ++i) {
        QGraphicsRectItem *stripe = new QGraphicsRectItem(0, 0, stripeHeight, 5);
        stripe->setPos(i * stripeHeight + 467, view->height() / 2+160);  // Adjust the position as needed
        stripe->setBrush(Qt::white);
        scene->addItem(stripe);
    }

    for (int i = 0; i < TotalStripes; ++i) {
        QGraphicsRectItem *stripe = new QGraphicsRectItem(0, 0, stripeHeight, 5);
        stripe->setPos(i * stripeHeight + 345, view->height() / 2-160);  // Adjust the position as needed
        stripe->setBrush(Qt::white);
        scene->addItem(stripe);
    }*/
    //scene->addItem(v);

    //view


    //positinner les feu de signalisation
    rect1->setPos(view->width()/2+153,view->height()/2+145);
    rect2->setPos(view->width()/3-2,view->height()/3 - 120);
    rect3->setPos(view->width()/2+175,view->height()/3-53);
    rect4->setPos(view->width()/3-60,view->height()/2+123);

    f2->setPos(view->width()/3+20,view->height()/3 - 50);
    f1->setPos(view->width()/2+175,view->height()/2+165);
    f3->setPos(view->width()/2+195,view->height()/3-30);
    f4->setPos(view->width()/3+10,view->height()/2+145);

    f22->setPos(view->width()/3+20,view->height()/3 - 75);
    f12->setPos(view->width()/2+175,view->height()/2+190);
    f32->setPos(view->width()/2+220,view->height()/3-30);
    f42->setPos(view->width()/3-15,view->height()/2+145);

    f23->setPos(view->width()/3+20,view->height()/3 - 100);
    f13->setPos(view->width()/2+175,view->height()/2+215);
    f33->setPos(view->width()/2+245,view->height()/3-30);
    f43->setPos(view->width()/3-40,view->height()/2+145);

    view->show();

    int pd,destination;

    pd=1;
    destination=2;

    // Créer un bouton
    QPushButton *boutton1 = new QPushButton("Ajouter Voiture");

    // Créer un widget graphique pour le bouton
    QGraphicsProxyWidget *Widget1 = new QGraphicsProxyWidget();
    Widget1->setWidget(boutton1);

    // Ajouter le widget graphique à la scène
    scene->addItem(Widget1);



    // Connecter le signal clicked du bouton à une fonction lambda
    QObject::connect(boutton1, &QPushButton::clicked, [scene,view,f1,f2,f3,f4,pd,destination]() {

        MyWidget *mywidget = new MyWidget(view->scene(), view, f1, f2, f3, f4);
        mywidget->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete the widget when closed
        mywidget->show();

    });

    QString font = "Segoe UI Variable Text Semibold";
    boutton1->setStyleSheet("QPushButton {"
                                "font: 600 13pt "+font+";"
                                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(51, 102, 153, 174), stop:1 rgba(85, 0, 0, 147));"
                                "color: white;"
                                "padding: 10px 10px;"
                                "border: none;"
                            "}"
                            "QPushButton:hover {"
                                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(51, 102, 153, 0), stop:1 rgba(51, 102, 153, 147));"
                            "}");

    return a.exec();
}
