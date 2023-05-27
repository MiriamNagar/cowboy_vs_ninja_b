#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Team.hpp"

namespace ariel{
class Team2:public Team 
{
    public:
    Team2(){}
    Team2(Character* leader):Team(leader){}
    ~Team2() override{}
   
    void add(Character* other)override;

    Team2(const Team2 &) = delete;
    Team2 &operator=(const Team2 &) = delete;
    Team2(Team2 &&) = delete;
    Team2 &operator=(Team2 &&) = delete;
};
}