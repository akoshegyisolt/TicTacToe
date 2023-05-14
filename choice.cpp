#include "choice.hpp"
#include "graphics.hpp"

using namespace genv;

Choice::Choice(int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, int menupy, int menusy): Widget(xx,yy,sxx,syy,rr,gg,bb), s(ss),mpy(menupy),msy(menusy)
{
    visible=false;
    active=false;
}
void Choice::draw()
{
    unsigned char rr,gg,bb;
    if(active){
        rr=255-r;
        gg=255-g;
        bb=255-b;
    }
    else{
        rr=r;
        gg=g;
        bb=b;
    }
    if(y>=mpy && y+sy<=mpy+msy){
        visible=true;
        gout << font("LiberationSans-Regular.ttf",18) << move_to(x,y) << color(rr,gg,bb) << box(sx,sy) << move_to(x,y) << color(255-rr,255-gg,255-bb) << line(sx,0) << line(0,sy) << line(-sx,0) << line(0,-sy)
        << move_to(x+sx/2-gout.twidth(s)/2,y+sy/2-gout.cascent()/2+gout.cdescent()/2) << text(s);
    }
    else{
        visible=false;
    }
}

void Choice::action(event ev)
{
    if(ev.button==btn_wheelup && !upper->visible){
        y+=sy-1;
    }
    else if(ev.button==btn_wheeldown && !lower->visible){
        y-=sy-1;
    }
    else if(ev.button==btn_left && visible){
        active=true;
    }
}

void Choice::setbosses(Choice* u, Choice* l)
{
    upper=u;
    lower=l;
}

void Choice::setactivity(bool b)
{
    active=b;
}

std::string Choice::gets()
{
    return s;
}
