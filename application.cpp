#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "menu.hpp"
#include "numbox.hpp"
#include <vector>
#include <fstream>
#include "statictext.hpp"
#include "eventbutton.hpp"

using namespace std;
using namespace genv;

Application::Application(int XX, int YY, unsigned char rr, unsigned char gg, unsigned char bb):r(rr), g(gg), b(bb)
{
    gout.open(XX,YY);
}

void Application::addmenu(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int choice_sizey, std::vector<string> v)
{
    menus.push_back(new Menu(this,xx,yy,sxx,syy,rr,gg,bb,choice_sizey,v));
}

void Application::addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, int mi, int ma)
{
    numboxes.push_back(new Numbox(this,xx,yy,sxx,syy,rr,gg,bb,mi,ma));
}

void Application::addnumbox(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb)
{
    numboxes.push_back(new Numbox(this,xx,yy,sxx,syy,rr,gg,bb));
}

void Application::addstatictext(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss)
{
    statictexts.push_back(new Statictext(this,xx,yy,sxx,syy,rr,gg,bb,ss));
}

void Application::addeventbutton(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, function<void(Application*)> m)
{
    eventbuttons.push_back(new Eventbutton(this, xx, yy, sxx, syy, rr, gg, bb, ss, m));
}

void Application::addfield(int xx, int yy, int _size,std::function<void(Application*)> m)
{

}

void Application::addwidget(Widget* nw)
{
    w.push_back(nw);
}

void Application::cclear()
{
    gout << move_to(0,0) << color(r,g,b) << box(X,Y);
}

void Application::log(ostream& out)
{
    for(int i=0; i<numboxes.size(); i++){
        out << "Numbox " << i+1 << ": " << numboxes[i]->getval() << endl;
    }
    for(int i=0; i<menus.size(); i++){
        out << "Menu " << i+1 << ": " << menus[i]->getval() << endl;
    }
    out << endl << endl;
}

void Application::eventloop()
{
    cclear();
    for(auto& c:w){
        c->draw();
    }
    gout << refresh;
    event ev;
    Widget* focus=nullptr;
    ofstream out("log.txt");
    if(!out.good()){
        cerr << "File error!\n";
        exit(2);
    }
    while(gin >> ev && ev.keycode!=key_escape){
        if(ev.button==btn_left){
            focus=nullptr;
            for(size_t i=0; i<w.size(); i++){
                if(w[i]->is_there(ev.pos_x, ev.pos_y)){
                    focus=w[i];
                }
            }
        }
        if(focus!=nullptr){
            focus->action(ev);
            focus->draw();
            gout << refresh;
        }
        if(ev.keycode==key_insert){
            log(out);
        }
    }
    out.close();
}
