#include "tictactoe.hpp"
#include "graphics.hpp"
#include "player.hpp"
#include <functional>

using namespace genv;

TicTacToe::TicTacToe(int board_size_x, int board_size_y, int tile_size, int target_to_win, unsigned char rr, unsigned char gg, unsigned char bb):boardx(board_size_x),boardy(board_size_y),fsize(tile_size), target(target_to_win), Application(board_size_x*tile_size,board_size_y*tile_size,rr,gg,bb)
{
    round=0;
    O=Player(boardx,boardy,target);
    X=Player(boardx,boardy,target);
    for(int i=0; i<boardx; i++){
        for(int j=0; j<boardy; j++){
            fields.push_back(new Field(this, i*fsize,j*fsize,fsize,[this,i, j](Eventbutton* s){
                if(free){
                   Field* sender=dynamic_cast<Field*>(s);
                   TicTacToe* _p=dynamic_cast<TicTacToe*>(sender->parent);
                   _p->step(i,j);
                   sender->free=false;
                   if(this->round){
                    sender->O=true;
                   }
                   else{
                    sender->X=true;
                   }
                }
            }));
        }
    }
}
void TicTacToe::step(int x, int y)
{
    if(round){
        if(O.addfield(x,y)){
            winner="O";
        }
    }
    else{
        if(X.addfield(x,y)){
            winner="X";
        }
    }
}
void TicTacToe::eventloop()
{
    event ev;
    Widget* focus=nullptr;
    for(Widget* h:w){
        h->draw();
    }
    gout << refresh;
    while(gin>>ev && ev.keycode!=key_escape){
        if(winner==""){
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
                //log(out);
            }
        }
        else{

        }
    }
}
