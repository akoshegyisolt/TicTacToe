#ifndef CHOICE_HPP_INCLUDED
#define CHOICE_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"

class Choice: public Widget
{
protected:
    std::string s;
    int msy, mpy;
    bool visible,active;
    Choice* upper;
    Choice* lower;
public:
    Choice(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, int menupy, int menusy);
    void draw() override;
    void action(genv::event ev) override;
    void setbosses(Choice* u, Choice*l);
    void setactivity(bool b);
    std::string gets();
};

#endif // CHOICE_HPP_INCLUDED
