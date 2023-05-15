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
    std::vector<Widget*> w;
    std::vector<Menu*> menus;
    std::vector<Numbox*> numboxes;
    std::vector<Statictext*> statictexts;
    std::vector<Eventbutton*> eventbuttons;

    int X,Y;
    unsigned char r,g,b;
    void cclear();
    void log(std::ostream& out);
    friend class Field;
    int round;
public:
    Application(int XX, int YY, unsigned char rr, unsigned char gg, unsigned char bb);
    void addmenu(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int choice_sizey, std::vector<std::string> v);
    void addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int mi, int ma);
    void addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb);
    void addstatictext(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss);
    void addeventbutton(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, std::function<void(Application*)> m);
    void addfield(int xx, int yy, int _size,std::function<void(Application*)> m);
    void addwidget(Widget* nw);
    void eventloop();
};

#endif // APPLICATION_HPP_INCLUDED
