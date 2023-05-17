#include "player.hpp"
#include <vector>

Player::Player(int boardxx, int boardyy, int n):target(n),boardx(boardxx),boardy(boardyy)
{
    board=std::vector<std::vector<bool>>(boardx,std::vector<bool>(boardy,false));
}

Player::Player(){}

bool Player::addfield(int x, int y)
{
    board[x][y]=true;
    int n=0;
    bool won=false;
    for(int i=0; i<boardx; i++){
        n=0;
        for(int j=0; j<boardy; j++){
            if(board[i][j]){
                n++;
            }
            else{
                n=0;
            }
            if(n==target){
                return true;
            }
        }
    }
    for(int j=0; j<boardx; j++){
        n=0;
        for(int i=0; i<boardy; i++){
            if(board[i][j]){
                n++;
            }
            else{
                n=0;
            }
            if(n==target){
                return true;
            }
        }
    }
    n=0;
    int i=0, j=0;
    while(i<boardx && j<boardy){
        if(board[i][j]){
            n++;
        }
        else{
            n=0;
        }
        if(n==target){
            return true;
        }
        i++;
        j++;
    }
    i=boardx-1;
    j=boardy-1;
    n=0;
    while(i>=0 && j>=0){
        if(board[i][j]){
            n++;
        }
        else{
            n=0;
        }
        if(n==target){
            return true;
        }
        i--;
        j--;
    }
    return false;
}

void Player::reset()
{
    for(size_t i=0; i<board.size(); i++){
        for(size_t j=0; j<board[i].size(); j++){
            board[i][j]=0;
        }
    }
}
