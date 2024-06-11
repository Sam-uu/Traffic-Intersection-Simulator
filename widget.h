#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include <QGraphicsScene>
#include <QSpinBox>
#include "feusignalisation.h"
#include "ui_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QGraphicsScene *scene, QGraphicsView *view, FeuSignalisation *f1, FeuSignalisation *f2, FeuSignalisation *f3, FeuSignalisation *f4, FeuSignalisation *f12, FeuSignalisation *f22, FeuSignalisation *f32, FeuSignalisation *f42, FeuSignalisation *f13, FeuSignalisation *f23, FeuSignalisation *f33, FeuSignalisation *f43, QWidget *parent = nullptr);

    ~Widget();
    int getVitesseValue() const { return ui->spinBox_3->value(); }

public slots:
    void onOkButtonClicked();

private:

    QGraphicsScene *scene;
    QGraphicsView *view;

    FeuSignalisation *f1;
    FeuSignalisation *f2;
    FeuSignalisation *f3;
    FeuSignalisation *f4;

    FeuSignalisation *f12;
    FeuSignalisation *f22;
    FeuSignalisation *f32;
    FeuSignalisation *f42;

    FeuSignalisation *f13;
    FeuSignalisation *f23;
    FeuSignalisation *f33;
    FeuSignalisation *f43;

    Ui::Widget *ui;

    QSpinBox *redvalue;
    QSpinBox *yellowvalue;
    QSpinBox *greenvalue;
};

#endif // WIDGET_H
