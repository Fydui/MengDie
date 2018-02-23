#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QPixmap>
#include <QString>


class Item : public QGraphicsItem
{
public:
    Item();
    Item(QString path);
    ~Item();
    Item* addPixmap(QString pat);
    Item* paintTopBar();
    Item* paintClickTextBar();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    QRectF boundingRect() const;
    void move(qreal x, qreal y);
    //void scale();

    QPixmap pix;
    int qx;
    int qy;
};

#endif // ITEM_H
