#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel{
class Team
{
    private:
    Character* leader;
    std::vector<Character*> members;

    public:
    Team():leader(nullptr){}
    Team(Character* leader);
    virtual ~Team() {}

    virtual void add(Character* other);
    virtual void attack(Team* enemy);
    int stillAlive();
    void print() const;
    

    //extra functions
    void findLeader();
    Character* findSacrifice(Team* enemy);
    void attackSacrifice(Character *sacrifice, Team *enemy);


    //getters & setters
    Character* getLeader() const{return leader;}
    void setLeader(Character* newL){leader = newL;}
    std::vector<Character*>& getMembers()
    {
        return members;
    }
    


    Team(const Team &) = delete;
    Team &operator=(const Team &) = delete;
    Team(Team &&) = delete;
    Team &operator=(Team &&) = delete;
};
}
