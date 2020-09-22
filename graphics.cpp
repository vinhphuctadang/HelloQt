#include "graphics.h"
#include <QPainter>
#include "math.h"

graphics::graphics(QWidget *parent) : QWidget(parent){

}

void graphics::baiTap1(QPainter& painter){

    float circleRadius = 200;
    QPoint center = QPoint(this->width()/2, this->height()/2);

    QPen pen(Qt::black);
    pen.setWidth(3);

    float halfSquareEdge = circleRadius / sqrt(2.0);
    painter.setPen(pen);
    painter.drawEllipse(center, circleRadius, circleRadius);
    painter.drawRect(
        QRect(center.x() - halfSquareEdge, center.y() - halfSquareEdge, halfSquareEdge * 2, halfSquareEdge * 2)
    );

    painter.setPen(Qt::black);
    painter.drawLine(center.x(), center.y()-circleRadius-30, center.x(), center.y()+circleRadius+30);
    painter.drawLine(center.x()-circleRadius-30, center.y(), center.x()+circleRadius+30, center.y());
}

void graphics::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);
    QPen defaultPen = painter.pen();
    // paint
    switch(this->baitap) {
        case 0:
                baiTap1(painter);
                break;
        case 1:
            baiTap2(painter);
            break;
        case 2:
            baiTap3(painter);
            break;
        case 3:
            baiTap4(painter);
            break;
    }

    // restore default pen
    painter.setPen(defaultPen);
}

void graphics::baiTap2(QPainter& painter) {

    float circleRadius = 200;
    QPen pen(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);

    QPoint center = QPoint(this->width()/2, this->height()/2);
    painter.drawEllipse(center, circleRadius, circleRadius);

    painter.drawEllipse(QPoint(center.x()-circleRadius/2, center.y()), 20, 20);
    painter.drawEllipse(QPoint(center.x()+circleRadius/2, center.y()), 20, 20);

    float smallerRadius = circleRadius / 2;
    QRect rect(center.x()-circleRadius, center.y()-smallerRadius, smallerRadius*2, smallerRadius*2);
    painter.drawArc(rect, 180*16, 180*16);
    QRect fliprect(center.x(), center.y()-smallerRadius, smallerRadius*2, smallerRadius*2);
    painter.drawArc(fliprect, 0*16, 180*16);
}

void graphics::baiTap3(QPainter& painter) {


    QPoint points[] = {
            QPoint(100, 100),
            QPoint(200, 200),
            QPoint(200, 400),
            QPoint(0, 400),
            QPoint(0, 200),
            QPoint(100, 100)
    };

    painter.drawRect(25, 100, 30, 100);
    // translate
    painter.setBrush(Qt::white);

    painter.drawPolygon(points, 6);
    painter.drawRect(25, 300, 50, 100);
    painter.drawRect(125, 250, 25, 25);
}

float min(float x, float y) {
    return x > y ? y : x;
}

void graphics::baiTap4(QPainter& painter) {
    float width = min((this->width()-1)/8, (this->height()-1)/8);

    for(int i = 0; i<8; ++i) {
        for(int j = 0; j<8; ++j) {
            if ((i % 2) ^ (j % 2))
                painter.setBrush(Qt::black);
            else
                painter.setBrush(Qt::white);
            painter.drawRect(i*width, j*width, width, width);

        }
    }
}
