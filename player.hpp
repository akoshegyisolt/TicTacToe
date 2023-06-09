#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <vector>

class Player
{
protected:
    std::vector<std::vector<bool>> board;
    int target,boardx,boardy;
public:
    Player(int boardxx, int boardyy, int n);
    Player();
    bool addfield(int x,int y);
    void reset();
};

#endif // PLAYER_HPP_INCLUDED
