#include "statictext.hpp"

using namespace std;
using namespace genv;

Statictext::Statictext(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss):
    Widget(a,xx,yy,sxx,syy,rr,gg,bb),s(ss){}
void Statictext::draw()
{
    gout << move_to(x,y) << color(r,g,b) << box(sx,sy) << font("LiberationSans-Regular.ttf",18) << move_to(x+sx/2-gout.twidth(s)/2,y+sy/2-gout.cascent()+gout.cdescent()) << color(255-r,255-g,255-b) << text(s);
}
void Statictext::changetext(string ss)
{
    s=ss;
}
