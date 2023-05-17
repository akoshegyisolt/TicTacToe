#include "widget.hpp"
#include "graphics.hpp"
#include "application.hpp"
Widget::Widget(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb):parent(a), x(xx), y(yy), sx(sxx), sy(syy), r(rr), g(gg), b(bb)
{
    a->addwidget(this);
}

Widget::Widget(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb): x(xx), y(yy), sx(sxx), sy(syy), r(rr), g(gg), b(bb){}

Widget::~Widget()
{
    parent->deletewidget(this);
}

void Widget::action(genv::event ev){}
bool Widget::is_there(int px, int py)
{
    if(px>=x && px<=x+sx && py>=y && py<=y+sy){
        return true;
    }
    return false;
}
