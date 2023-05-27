#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Team.hpp"

namespace ariel{
class SmartTeam:public Team
{
    public:
    SmartTeam(){}
    SmartTeam(Character* leader):Team(leader){}
    ~SmartTeam() override{}

    void add(Character* other)override;
    void attack(Team* enemy)override;
    // int stillAlive() const override;
    // void print() const override;

    void findLeader(Team* enemy);
    // Character* findSacrifice(Team* enemy);
    // void attackSacrifice(Character *sacrifice, Team *enemy) override;
    int countHitsSacrifice(Character *sacrifice, Team *enemy, Character*leader);

    SmartTeam(const SmartTeam &) = delete;
    SmartTeam &operator=(const SmartTeam &) = delete;
    SmartTeam(SmartTeam &&) = delete;
    SmartTeam &operator=(SmartTeam &&) = delete;
};
}