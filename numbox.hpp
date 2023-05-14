#ifndef NUMBOX_HPP_INCLUDED
#define NUMBOX_HPP_INCLUDED
#include "widget.hpp"
#include "application.hpp"

class Numbox: public Widget
{
protected:
    int val,maxval,minval;
public:
    Numbox(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int mi, int ma);
    Numbox(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb);
    void draw() override;
    void action(genv::event ev) override;
    int getval();
};

#endif // NUMBOX_HPP_INCLUDED
