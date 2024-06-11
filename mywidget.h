#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QDialog>
#include <QGraphicsScene>
#include <QSpinBox>
#include "feusignalisation.h"
#include "ui_mywidget.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QDialog
{
    Q_OBJECT

public:
    explicit MyWidget(QGraphicsScene *scene, QGraphicsView *view, FeuSignalisation *f1, FeuSignalisation *f2, FeuSignalisation *f3, FeuSignalisation *f4, QWidget *parent = nullptr);
    ~MyWidget();
    int getVitesseValue() const { return ui->spinBox_3->value(); }

public slots:
    void onOkButtonClicked();

private:
    void createVehicule(int pd, int destination, int vitesse);

    QGraphicsScene *scene;
    QGraphicsView *view;

    FeuSignalisation *f1;
    FeuSignalisation *f2;
    FeuSignalisation *f3;
    FeuSignalisation *f4;

    Ui::MyWidget *ui;

    QSpinBox *departSpinBox;
    QSpinBox *destinationSpinBox;
};

#endif // MYWIDGET_H
