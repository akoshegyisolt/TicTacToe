#include "tictactoe.hpp"
#include "graphics.hpp"
#include "player.hpp"
#include <functional>
#include <iostream>

using namespace genv;

TicTacToe::TicTacToe(int board_size_x, int board_size_y, int tile_size, int target_to_win, unsigned char rr, unsigned char gg, unsigned char bb):boardx(board_size_x),boardy(board_size_y),fsize(tile_size), target(target_to_win), Application(board_size_x*tile_size,board_size_y*tile_size,rr,gg,bb)
{
    round=0;
    O=Player(boardx,boardy,target);
    X=Player(boardx,boardy,target);
    for(int i=0; i<boardx; i++){
        for(int j=0; j<boardy; j++){
            fields.push_back(new Field(this, i*fsize,j*fsize,fsize,[this,i, j](Eventbutton* s){
                Field* sender=dynamic_cast<Field*>(s);
                if(sender->free){
                   TicTacToe* _p=dynamic_cast<TicTacToe*>(sender->parent);
                   sender->free=false;
                   if(this->round){
                    sender->O=true;
                   }
                   else{
                    sender->X=true;
                   }
                   _p->step(i,j);
                }
            }));
        }
    }
}

void TicTacToe::reset()
{
    X.reset();
    O.reset();
    winner="";
    for(size_t i=0; i<board.size(); i++){
        for(size_t j=0; j<board[i].size(); j++){
            board[i][j]=false;
        }
    }
    for(size_t i=0; i<fields.size(); i++){
        fields[i]->reset();
    }
    for(Widget* h:w){
        h->draw();
    }
    gout << refresh;
}

void TicTacToe::step(int x, int y)
{
    if(round){
        if(O.addfield(x,y)){
            winner="O";
        }
        round=false;
    }
    else{
        if(X.addfield(x,y)){
            winner="X";
        }
        round=true;
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
            std::string msg=winner+" won!";
            std::cout << msg << std::endl;
            Eventbutton again(this,0,0,200,200,255,255,255,"Play again",[](Eventbutton* sender){
                    TicTacToe* p=dynamic_cast<TicTacToe*>(sender->parent);
                    p->reset();
                    std::cout << "hi";
                              });
            again.draw();
            gout << refresh;
            if(again.is_there(ev.pos_x,ev.pos_y) && ev.button==btn_left){
                again.action(ev);
            }
        }
    }
}
