#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "application.hpp"
#include <vector>

class Player
{
protected:
    std::vector<std::vector<bool>> board;
    int target,boardx,boardy;
public:
    Player(int boardxx, int boardyy, int n);
    bool addfield(int x,int y);
};

#endif // PLAYER_HPP_INCLUDED
