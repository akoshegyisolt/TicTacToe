#ifndef TICTACTOE_HPP_INCLUDED
#define TICTACTOE_HPP_INCLUDED

#include "application.hpp"
#include "player.hpp"
#include "field.hpp"

class TicTacToe:public Application
{
protected:
    int boardx, boardy, fsize, target;
    bool round;
    Player X,O;
    std::vector<Field*> fields;
    std::vector<std::vector<bool>> board;
    std::string winner="";
    Eventbutton* again;
    Statictext* message;
public:
    TicTacToe(int board_size_x, int board_size_y, int tile_size, int target_to_win, unsigned char rr, unsigned char gg, unsigned char bb);
    void step(int x, int y);
    void eventloop() override;
    void reset();
};

#endif // TICTACTOE_HPP_INCLUDED
