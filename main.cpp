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
    my.move(-300,0);
    
    w.setScene(&my);
    //Item my2("D:/code/MyObj/MengDie_Widget/resources/image/Lexington.png");
    //w.setScene(&my2);
    
    //Item my3("Lexington/UI/user_detail_bg1.png");
    //my3.move(-300,0);
    //w.setScene(&my3);
       
    w.show();
    
    return a.exec();
}
