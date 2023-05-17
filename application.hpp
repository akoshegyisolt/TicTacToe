#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <functional>

class Widget;
class Menu;
class Numbox;
class Statictext;
class Eventbutton;
class Field;

class Application
{
protected:
    std::vector<Menu*> menus;
    std::vector<Widget*> w;
    std::vector<Numbox*> numboxes;
    std::vector<Statictext*> statictexts;
    std::vector<Eventbutton*> eventbuttons;
    int XX,YY;
    unsigned char r,g,b;
    void cclear();
    void log(std::ostream& out);
public:
    Application(int XX, int YY, unsigned char rr, unsigned char gg, unsigned char bb);
    void addmenu(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int choice_sizey, std::vector<std::string> v);
    void addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int mi, int ma);
    void addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb);
    void addstatictext(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss);
    void addeventbutton(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, std::function<void(Eventbutton*)> m);
    void addwidget(Widget* nw);
    virtual void eventloop();
    void deletewidget(Widget* ow);
};

#endif // APPLICATION_HPP_INCLUDED
