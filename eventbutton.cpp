#include "eventbutton.hpp"
#include "statictext.hpp"
#include "application.hpp"
#include <functional>

using namespace std;
using namespace genv;

Eventbutton::Eventbutton(Application* a, int xx, int yy, int sxx, int syy, unsigned char rr, unsigned char gg, unsigned char bb, std::string ss, std::function<void(Application*)> m):
    Statictext(a,xx,yy,sxx,syy,rr,gg,bb,ss), evt(m){}
void Eventbutton::action(event ev)
{
    if(ev.button==btn_left){
        evt(parent);
    }
}
