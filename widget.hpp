#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include "application.hpp"


class Widget
{
protected:
    int x,y,sx,sy;
    unsigned char r,g,b;
public:
    Widget(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb);
    Widget(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb);
    ~Widget();
    virtual void draw()=0;
    virtual void action(genv::event ev);
    bool is_there(int px, int py);
    Application* parent;
};

#endif // WIDGET_HPP_INCLUDED
