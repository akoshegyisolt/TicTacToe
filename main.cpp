#include "application.hpp"
#include "tictactoe.hpp"

int main()
{
    TicTacToe ttt(15,15,30,5,0,0,0);
    ttt.eventloop();
    return 0;
}
