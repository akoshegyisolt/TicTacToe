#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "widget.hpp"
#include "choice.hpp"
#include <vector>
#include "application.hpp"

class Menu: public Widget
{
protected:
    std::vector<Choice> choices;
    int choice_size;
    Choice* active;
public:
    Menu(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int choice_sizey, std::vector<std::string> v);
    void draw() override;
    void action(genv::event ev) override;
    std::string getval();
};


#endif // MENU_HPP_INCLUDED
