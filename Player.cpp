#include <iostream>
#include <cstring>
#include "player.h"
Player::Player(char const* n,int s): name(nullptr),score(s)
{
    setName(n);
}
Player::Player(Player const& p):name(nullptr),score(p.score)
{
  setName(p.name);
}
Player& Player::operator=(Player const& p)
{
  if(this!=&p){
    setName(p.name);
    setscore(p.score);
  }
  return *this;
}

void Player::setName(char const* n)
{
    delete [] name;
    const int Name_lenght=strlen(n);
    name=new char[Name_lenght+1];
    strcpy(name,n);

}
void Player::setscore(int s)
{
  score=s;
}
void Player::print() const
{
    std::cout << "Player" << name
            << " has " << score << " points "
            << std::endl;

}
Player::~Player()
{
   delete[] name;
}
