#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "eventbutton.hpp"
#include "graphics.hpp"
#include "application.hpp"

class Field: public Eventbutton
{
protected:
    bool O,X,free;
public:
    Field(Application* a, int xx, int yy, int _size,std::function<void(Application*)> m);
    void draw() override;
    void action(genv::event ev) override;
};

#endif // FIELD_HPP_INCLUDED
