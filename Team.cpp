#include <iostream>
#include <cstring>
#include "player.h"
#include "Team.h"
class Team
{
    Team::Team(Player const& pl,int number)number_of_players(number),player(nullptr)
    {
        for(int i=0; i<number_of_players; i++)
        {
            player[i]=pl[i]
        }
    }
    Team::Team(Team const& t)number_of_players(t.number_of_users),player(nullptr)
    {
        for(int i=0; i<number_of_players; i++)
        {
            player[i]=pl[i]
        }
    }
    Team& Team::operator=(Team const& t){
    if(this!=&t){
        number_of_players=t.number_of_players;
        for(int i=0;i<number_of_players;i++){
        player[i]=t.players[i]
        }
    }
    }
    Team::~Team()=default;
    void Team::setnumberofplayers(int s){
    number_of_players=s;
    }
    void Team::print()const{
    std::cout<<"Number of players:"<<number_of_players<<std::endl;
    for(int i=0;i<number_of_players;i++){
        std::cout<<players[i]<<std::endl;
        }
    }
};

