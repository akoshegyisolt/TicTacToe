#ifndef EVENTBUTTON_HPP_INCLUDED
#define EVENTBUTTON_HPP_INCLUDED

#include "statictext.hpp"
#include <functional>
#include "application.hpp"

class Eventbutton: public Statictext
{
protected:
    std::function<void(Application*)> evt;
public:
    Eventbutton(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, std::function<void(Application*)> m);
    void action(genv::event ev) override;
};

#endif // EVENTBUTTON_HPP_INCLUDED
