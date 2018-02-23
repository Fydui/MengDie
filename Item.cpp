#include "Item.h"
extern double defaultWindowHeight;
extern double defaultWindowWidth;
extern double screenWindowHeight;
extern double screenWindowWidth;
extern double screenHeightDifference;
extern double screenWidthDifference;
extern double deskWidth;
extern double deskHeight;

extern QString prePath;

Item::Item()
{
    this->setPos(-(deskWidth/2-pix.width()/2),-(deskHeight/2-pix.height()/2));    
    qx = 0;
    qy = 0;
}

Item::~Item()
{
    
}
 
Item::Item(QString path)
{
    bool t = pix.load(prePath + path); //加载图片
    qx = 0;
    qy = 0;
    this->setPos(-(deskWidth/2-pix.width()/2),-(deskHeight/2-pix.height()/2));
    //因为QGraphicsScene的原点为窗口中心, 为了习惯手动设置锚点到左上角(至少看上去是                
}

Item* Item::addPixmap(QString path)
{ 
    pix.load(prePath+path);
    this->setPos(-(deskWidth/2-pix.width()/2),-(deskHeight/2-pix.height()/2));   
    return this;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   
    painter->drawPixmap(boundingRect().toRect(),pix);         
}

QRectF Item::boundingRect() const
{
    qreal penwidth = 0;
    return QRectF(-pix.width()/2+penwidth,-pix.height()/2+penwidth,
                  pix.width()+penwidth*2,pix.height()+penwidth*2);  //绘制范围
}

void Item::move(qreal x, qreal y)
{
    setPos(-(deskWidth/2-pix.width()/2)+x,-(deskHeight/2-pix.height()/2)+y);
    qx = x;
    qy = y;
}

