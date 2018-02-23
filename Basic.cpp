#include "Basic.h"
QGraphicsScene* scene = nullptr;    //总场景 管理全部视图以及视图的图元
QGraphicsView* view = nullptr;      //视图

double defaultWindowHeight;         //默认窗口的大小
double defaultWindowWidth;
double screenWindowHeight;          //可用桌面的大小
double screenWindowWidth;
double deskWidth;                   //单块屏幕总大小
double deskHeight;
double screenHeightDifference;      //总大小与可用大小的差值
double screenWidthDifference;

double widthZoomVar=1;              //默认长宽与当前长宽的比值 用于缩放图元
double heightZoomVar=1;
double zoomVar=1;

extern QString prePath = ""; //安卓下的预路径 请在sdcard下自建MengDieOBJ梦蝶工程文件夹 将包放在该目录下

Basic::Basic(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(this->titleName);
    defaultWindowHeight = 640;
    defaultWindowWidth = 360;
    
    getWindowSize();                                                  //获得窗口大小数据   
    //setWindowSize(1080,720);
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);       //关闭横竖滚动栏
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    
    this->setFixedSize(deskWidth,deskHeight);        //固定窗口大小
    view->resize(deskWidth+2,deskHeight+2);          //设置视图范围
    scene->setParent(this);                          //设置scene的父窗口
    view->setParent(this);                           //设置view的父窗口
    //view->setSceneRect(0,0,deskWidth,deskHeight); 
    scene->setSceneRect(-deskWidth/2,-deskHeight/2,deskWidth,deskHeight); //设置scene大小    
    view->setScene(scene);                              //通过view显示scene
}

Basic::Basic(QWidget *parent, bool s)
    :QWidget(parent) 
{
    setWindowTitle("梦蝶");
    defaultWindowHeight = 640;
    defaultWindowWidth = 360;
    
    getWindowSize();                                                  //获得窗口大小数据   
    setFixed(s);
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);       //关闭横竖滚动栏
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    
    this->setFixedSize(deskWidth,deskHeight);        //固定窗口大小
    view->resize(deskWidth+2,deskHeight+2);          //设置视图范围
    scene->setParent(this);                          //设置scene的父窗口
    view->setParent(this);                           //设置view的父窗口
    //view->setSceneRect(0,0,deskWidth,deskHeight); 
    scene->setSceneRect(-deskWidth/2,-deskHeight/2,deskWidth,deskHeight); //设置scene大小    
    view->setScene(scene);                              //通过view显示scene
}

Basic::~Basic()
{
    delete scene;
}

void Basic::getWindowSize()
{
    QDesktopWidget desktopWidget;
    QRect deskRect = desktopWidget.availableGeometry(); //获得可用窗口大小(去除通知栏/任务栏的大小)
    QRect screenRect = desktopWidget.screenGeometry();  //获得当前桌面的大小(整块屏幕总大小)
    
    screenWindowHeight = deskRect.height();             
    screenWindowWidth = deskRect.width(); 
    
    deskHeight = screenRect.height();
    deskWidth = screenRect.width();
    
    screenHeightDifference = screenRect.height() - screenWindowHeight;
    screenWidthDifference = screenRect.width() - screenWindowWidth;
    
    widthZoomVar =  screenWindowWidth/defaultWindowWidth;   //计算窗口横竖缩放比值
    heightZoomVar = screenWindowHeight/defaultWindowHeight;    
    zoomVar = widthZoomVar*heightZoomVar;                   //计算面积比值
    
}

void Basic::setWindowSize(int w, int h)
{
    screenWindowHeight = h;            
    screenWindowWidth = w; 
    
    deskHeight = h;
    deskWidth = w;
    
    screenHeightDifference = 0;
    screenWidthDifference = 0;
    
    widthZoomVar =  screenWindowWidth/defaultWindowWidth;   //计算窗口横竖缩放比值
    heightZoomVar = screenWindowHeight/defaultWindowHeight;    
    zoomVar = widthZoomVar*heightZoomVar;                   //计算面积比值
}

void Basic::setScene(Item *item)
{
    scene->addItem(item);
    autoZoom(item);
}

bool Basic::openPackage(QString packName)
{
    
}

void Basic::setPrePath(QString path)
{
    prePath = path;
}

void Basic::setFixed(bool s)
{
    if(s == false){
        
    }
    else{
        deskWidth = defaultWindowWidth;
        deskHeight = defaultWindowHeight;
    }
}


QString Basic::getPrePath()
{
    return prePath;
}

void Basic::autoZoom(Item *item) //这个功能用人话讲就是你在电脑上360*640窗口大小下看到的UI啥样 不管到啥分辨率的手机上, UI都是那样
{
    zoomVar = 1;//(deskWidth*deskHeight)/(defaultWindowWidth*defaultWindowHeight);    
    item->setScale(zoomVar); 
    int pixWidth = item->boundingRect().width();
    int pixHeight = item->boundingRect().height();
    item->move((pixWidth*zoomVar)/2 - pixWidth/2 + item->qx*zoomVar, pixHeight*zoomVar/2 - pixHeight/2 + item->qy*zoomVar);
    //item->move(item->qx, item->qy);
}

