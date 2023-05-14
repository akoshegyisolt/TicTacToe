#include "graphics.hpp"
#include "menu.hpp"
#include "choice.hpp"
#include <vector>
#include "application.hpp"

using namespace std;
using namespace genv;

Menu::Menu(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int choice_sizey, std::vector<string> v):
    Widget(a,xx,yy,sxx,syy,rr,gg,bb), choice_size(choice_sizey)
{
    for(size_t i=0; i<v.size(); i++){
        choices.push_back(Choice(x,y+choice_size*i-i,sx,choice_size,r,g,b,v[i],y,sy));
    }
    for(Choice& c:choices){
        c.setbosses(&choices[0], &choices[choices.size()-1]);
    }
    active=nullptr;
}

void Menu::action(event ev)
{
    if(ev.button==btn_left){
        active=nullptr;
        for(Choice& c:choices){
            c.setactivity(false);
        }
        for(Choice& c:choices){
            if(c.is_there(ev.pos_x, ev.pos_y)){
                active=&c;
                c.action(ev);
                break;
            }
        }
    }
    else if(ev.button==btn_wheelup || ev.button==btn_wheeldown){
        for(Choice& c:choices){
            c.action(ev);
        }
    }
}

void Menu::draw()
{
    gout << move_to(x,y) << color(r,g,b) << box(sx,sy);
    for(Choice& c:choices){
        c.draw();
    }
}

string Menu::getval()
{
    if(active!=nullptr){
        return active->gets();
    }
    return "";
}
