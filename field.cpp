#include "field.hpp"
#include <functional>
#include "graphics.hpp"
#include <cmath>

using namespace genv;

Field::Field(Application* a, int xx, int yy, int _size, std::function<void(Application*)> m):Eventbutton(a,xx,yy,_size, _size, 0,0,0,"",m)
{
    O=X=false;
    free=true;
}

void Field::draw()
{
    gout << move_to(x,y) << color(255-r,255-g,255-b) << box(sx,sy) << move_to(x+1,y+1) << color(r,g,b) << box(sx-2,sy-2);
    if(X){
        gout << move_to(x+3,y+3) << color(255-r, 255-g,255-b) << line(sx-6,sy-6) << move_to(x+sx-3,y+sy-3) << line(-sx+6,-sy+6);
    }
    else if(O){
        gout << color(255-r, 255-g,255-b);
        for(int i=x; i<=x+sx; i++){
            for(int j=y; j<=y+sy; j++){
                if(pow(i-(x+sx/2),2)+pow(j-(y+sy/2),2)<pow(sx-6,2)){
                    gout << move_to(i,j) << dot;
                }
            }
        }
        gout << color(r,g,b);
        for(int i=x; i<=x+sx; i++){
            for(int j=y; j<=y+sy; j++){
                if(pow(i-(x+sx/2),2)+pow(j-(y+sy/2),2)<pow(sx-8,2)){
                    gout << move_to(i,j) << dot;
                }
            }
        }
    }
}

void Field::action(event ev)
{
    evt(parent);
    parent->round;
}
