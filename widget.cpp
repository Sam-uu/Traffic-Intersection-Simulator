#include "widget.h"
#include "ui_widget.h"
#include "vehicule.h"
#include <QGraphicsView>

Widget::Widget(QGraphicsScene *scene, QGraphicsView *view, FeuSignalisation *f1, FeuSignalisation *f2, FeuSignalisation *f3, FeuSignalisation *f4, FeuSignalisation *f12, FeuSignalisation *f22, FeuSignalisation *f32, FeuSignalisation *f42, FeuSignalisation *f13, FeuSignalisation *f23, FeuSignalisation *f33, FeuSignalisation *f43, QWidget *parent)
    : QDialog(parent), scene(scene), view(view), f1(f1), f2(f2), f3(f3), f4(f4), f12(f12), f22(f22), f32(f32), f42(f42), f13(f13), f23(f23), f33(f33), f43(f43), ui(new Ui::Widget)
{
    ui->setupUi(this);

    redvalue = ui->spinBox;
    yellowvalue = ui->spinBox_2;
    greenvalue = ui->spinBox_3;
    setTabOrder(ui->spinBox, ui->spinBox_2);
    setTabOrder(ui->spinBox_2, ui->spinBox_3);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Widget::onOkButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onOkButtonClicked()
{
    int redTimer = redvalue->value();
    int yellowTimer = redvalue->value();
    int greenTimer = greenvalue->value();

    // Set timer values after creating the objects
    f1->setTimerValues(redTimer, yellowTimer, greenTimer);
    f2->setTimerValues(redTimer, yellowTimer, greenTimer);
    f3->setTimerValues(redTimer, yellowTimer, greenTimer);
    f4->setTimerValues(redTimer, yellowTimer, greenTimer);

    f12->setTimerValues(redTimer, yellowTimer, greenTimer);
    f22->setTimerValues(redTimer, yellowTimer, greenTimer);
    f32->setTimerValues(redTimer, yellowTimer, greenTimer);
    f42->setTimerValues(redTimer, yellowTimer, greenTimer);

    f13->setTimerValues(redTimer, yellowTimer, greenTimer);
    f23->setTimerValues(redTimer, yellowTimer, greenTimer);
    f33->setTimerValues(redTimer, yellowTimer, greenTimer);
    f43->setTimerValues(redTimer, yellowTimer, greenTimer);

    //createVehicule(departValue, destinationValue, vitesseValue);
}
