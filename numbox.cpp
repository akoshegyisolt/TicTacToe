#include "graphics.hpp"
#include "numbox.hpp"
#include <sstream>
#include "application.hpp"

using namespace genv;

Numbox::Numbox(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb,int mi, int ma): Widget(a,xx,yy,sxx,syy,rr,gg,bb),maxval(ma),minval(mi)
{
    val=0;
}
Numbox::Numbox(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb):Widget(a,xx,yy,sxx,syy,rr,gg,bb)
{
    val=0;
    minval=INT_MIN;
    maxval=INT_MAX;
}
void Numbox::draw()
{
    std::stringstream ss;
    ss<<val;
    std::string tmp;
    ss>>tmp;
    genv::gout << genv::move_to(x,y) << genv::color(r,g,b) << genv::box(sx,sy)
    << genv::move_to(x+sx-15,y) << genv::color(255-r, 255-g, 255-b) << genv::line(0,sy) << genv::move_to(x+sx-15, y+sy/2) << genv::line(15,0)
    << genv::move_to(x+sx-15+3,y+sy/2-sy/4+3) << genv::line(5,-5) << genv::line(5,5) << genv::line(-9,0)
    << genv::move_to(x+sx-15+3,y+sy-sy/4-3) << genv::line(5,5) << genv::line(5,-5) << genv::line(-9,0)
    << font("LiberationSans-Regular.ttf",18) << genv::move_to(x+(sx-15)/2-gout.twidth(tmp)/2, y+sy/2-gout.cascent()+gout.cdescent()) << genv::text(tmp);
}
void Numbox::action(genv::event ev)
{
    if(ev.button==btn_left){
        if(ev.pos_x>x+sx-15 && ev.pos_x<=x+sx){
            if(ev.pos_y>y && ev.pos_y<y+sy/2){
                val++;
            }
            else if(ev.pos_y>y+sy/2 && ev.pos_y<y+sy){
                val--;
            }
        }
    }
    else if(ev.keycode==key_up){
        val++;
    }
    else if(ev.keycode==key_down){
        val--;
    }
    else if(ev.keycode==key_pgup){
        val+=10;
    }
    else if(ev.keycode==key_pgdn){
        val-=10;
    }
    if(val>maxval){
        val=maxval;
    }
    else if(val<minval){
        val=minval;
    }
}

int Numbox::getval()
{
    return val;
}
