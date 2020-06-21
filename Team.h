#pragma once
#include "Player.h"
class Team
{
private:
    Player players[30];
    int number_of_players;
public:
    Team(Player const& pl="<Anonimen>",int number=0);
    Team(Team const& t);
    Team& operator=(Team const& t);
    ~Team();
    int getnumberofplayers()const
    {
        return number_of_players;
    }
    const Player* getPlayer()const
    {
        return PLayer;
    }
    void setnumberofplayers(int s);
    void addplayer(Player const& player);
    void print()const;
};
