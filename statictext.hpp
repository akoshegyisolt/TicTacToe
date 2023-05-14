#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "widget.hpp"

class Statictext: public Widget
{
protected:
    std::string s;
public:
    Statictext(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss);
    void changetext(std::string ss);
    void draw() override;
};

#endif // STATICTEXT_HPP_INCLUDED
