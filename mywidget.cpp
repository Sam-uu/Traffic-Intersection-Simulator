#include "mywidget.h"
#include "ui_mywidget.h"
#include "vehicule.h"
#include <QGraphicsView>


MyWidget::MyWidget(QGraphicsScene *scene, QGraphicsView *view, FeuSignalisation *f1, FeuSignalisation *f2, FeuSignalisation *f3, FeuSignalisation *f4, QWidget *parent)
    : QDialog(parent), scene(scene), view(view), f1(f1), f2(f2), f3(f3), f4(f4), ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    departSpinBox = ui->spinBox;
    destinationSpinBox = ui->spinBox_2;
    setTabOrder(ui->spinBox, ui->spinBox_2);
    setTabOrder(ui->spinBox_2, ui->spinBox_3);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &MyWidget::onOkButtonClicked);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::onOkButtonClicked()
{
    int departValue = departSpinBox->value();
    int destinationValue = destinationSpinBox->value();
    int vitesseValue = getVitesseValue();

    createVehicule(departValue, destinationValue, vitesseValue);
}

void MyWidget::createVehicule(int pd, int destination, int vitesse)

{
    // Your existing code to create vehicule based on pd and destination
    if (pd == 1) {
        vehicule *v = new vehicule(f1, pd, destination, vitesse);
        scene->addItem(v);
        v->setPos(view->width() / 2 + 40, view->height() - v->pixmap().height()+52);
        // Make focusable
        v->setFlag(QGraphicsItem::ItemIsFocusable);
        v->setFocus();
    } else if (pd == 2) {
        vehicule *v = new vehicule(f2, pd, destination, vitesse);
        scene->addItem(v);
        v->setRotation(180);
        v->setPos(view->width() / 2, view->height() - view->height() + v->pixmap().height()-52);
        // Make focusable
        v->setFlag(QGraphicsItem::ItemIsFocusable);
        v->setFocus();
    } else if (pd == 3) {
        vehicule *v = new vehicule(f3, pd, destination, vitesse);
        scene->addItem(v);
        v->setRotation(270);
        v->setPos(view->width() - v->pixmap().height() +50, view->height() / 2 - 22);
        // Make focusable
        v->setFlag(QGraphicsItem::ItemIsFocusable);
        v->setFocus();
    } else if (pd == 4) {
        vehicule *v = new vehicule(f4, pd, destination, vitesse);
        scene->addItem(v);
        v->setRotation(90);
        v->setPos(view->width() / 10 + 40, view->height() / 2 + 10);
        // Make focusable
        v->setFlag(QGraphicsItem::ItemIsFocusable);
        v->setFocus();
    }
}
