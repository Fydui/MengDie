#ifndef WIDGET_H
#define WIDGET_H
#include <QPainter>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include "Item.h"

class Basic : public QWidget
{
    Q_OBJECT
    
public:
    Basic(QWidget *parent = 0);
    Basic(QWidget *parent = 0,bool s = 1);
    ~Basic();
    void getWindowSize();   //获得窗口大小
    void setWindowSize(int w, int h);//设置窗口大小
    void controlAdaptive(); //
    void setScene(Item &item); //设置item
    bool openPackage(QString packName); //设置梦蝶工程包
    void setPrePath(QString path);      //安卓下设置预目录
    void setFixed(bool s = 1); //在固定窗口与全屏自适应之间切换 默认固定
    QString getPrePath();
    
    QString titleName = "梦蝶";
    
private:
    void autoZoom(Item &item);    // 图元的自动缩放
    
};

#endif // WIDGET_H
