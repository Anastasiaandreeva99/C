#pragma once
const int MAX_NAME = 100;
class Player
{
private:
    char *name;
    int score;
public:
        Player(char const* n = "<Anonimen>",int s=0);
        Player(Player const& p);
        Player& operator=(Player const& p);
        char const* getName() const{
        return name;
        }
        int getScore() const{
        return score;
        }
        void setName(char const* n);
        void setscore(int s);
        void print()const;
        ~Player();
};
