#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPainter>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void baiTap1(QPainter& painter);
    void baiTap2(QPainter& painter);

    void baiTap3(QPainter& painter);
    void baiTap4(QPainter& painter);

    int baitap = 0;

signals:

public slots:

};

#endif // GRAPHICS_H
