#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "eventbutton.hpp"
#include "graphics.hpp"
#include "application.hpp"

class Field: public Eventbutton
{
public:
    Field(Application* a, int xx, int yy, int _size,std::function<void(Eventbutton*)> m);
    void draw() override;
    void action(genv::event ev) override;
    bool O,X,free;
};

#endif // FIELD_HPP_INCLUDED
