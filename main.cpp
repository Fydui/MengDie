#include "Basic.h"
#include "Item.h"
#include "sqlite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Basic w(0,1);
    w.setFixed(1);
    //w.setPrePath("/sdcard/MengDieOBJ/");
 
    Item my("D:/code/MyObj/MengDie_Widget/resources/image/user_detail_bg1.png");
    my.move(0,0);
    w.setScene(my);
    
    Item my2("D:/code/MyObj/MengDie_Widget/resources/image/Lexington.png");
    my2.move(-600,-500);
    w.setScene(my2);
    /*
    Item my3("Lexington/UI/user_detail_bg1.png");
    my3.move(0,0);
    w.setScene(my3);
    
    Item my4("Lexington/image/Lexington.png");
    my4.move(-600,-500);
    w.setScene(my4);*/
    
    
    w.show();    
    return a.exec();
}
