#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>

#include "SmartTeam.hpp"
using namespace std;
using namespace ariel;


// smartteam functions
void SmartTeam::add(Character* other)
{
    if(other->getMember())  throw runtime_error("Error: already a team member");
    for (Character* member : getMembers()) {
        if (other == member) {
            throw runtime_error("Error: already a member");
        }
    }
    if (getMembers().size() >= 10) throw runtime_error("ERROR: the team contains 10 members.");
    if(getMembers().size() < 10)
    {
        getMembers().insert(getMembers().begin(), other);
        other->setMember(true);   
    }
}


void SmartTeam::findLeader(Team* enemys)
{
    Character* newLeader = nullptr;
    Character* sacrifice = nullptr;
    double maxDamage = std::numeric_limits<double>::min();
    double damage = 0;
    if(!getLeader()->isAlive())
    {
        for(Character* member : getMembers())
        {
            sacrifice = this->findSacrifice(enemys);
            if(!sacrifice) return;
            damage = this->countHitsSacrifice(sacrifice, enemys, member);
            if(member->isAlive() && maxDamage < damage)
            {
                maxDamage = damage;
                newLeader = member;
            }
        }
        setLeader(newLeader);
    }
}

// Character* SmartTeam::findSacrifice(Team* enemys)
// {
//     Character* sacrifice = nullptr;
//     double minDistance = std::numeric_limits<double>::max();
//     double dis = 0;
//     for(Character* member : enemys->getMembers())
//     {
//         dis = member->distance(getLeader());
//         if(member->isAlive() && dis < minDistance)
//         {
//             minDistance = dis;
//             sacrifice = member;
//         }
//     }
//     return sacrifice;
// }

// void SmartTeam::attackSacrifice(Character *sacrifice, Team *enemys)
// {
//     for (Character* member : getMembers()) {
//         if (member == nullptr || sacrifice == nullptr) return;
//         if (member->isAlive() && sacrifice->isAlive()) {
//             if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
//                 if(cowboy->hasboolets())cowboy->shoot(sacrifice);
//                 else cowboy->reload();
//             }
//             else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
//                 if(ninja->distance(sacrifice)<=1.0) ninja->slash(sacrifice);
//                 else ninja->move(sacrifice);
//             }
//             if(!(sacrifice->isAlive())) sacrifice = findSacrifice(enemys);
//         }
//     }
// }

void SmartTeam::attack(Team* enemys)
{
    if(enemys == nullptr) throw std::invalid_argument("invalid enemys");
    if(enemys->stillAlive() == 0 || stillAlive() == 0) throw std::runtime_error("fight already ended");
    if (!getLeader()) throw std::invalid_argument("ERROR: leader argument invalid");
    findLeader(enemys);
    if(!getLeader()) return;
    Character* sacrifice = findSacrifice(enemys);
    if(!sacrifice) return;
    attackSacrifice(sacrifice, enemys);
}

int SmartTeam::countHitsSacrifice(Character *sacrifice, Team *enemys, Character*leader)
{
    int count = 0;
    for (Character* member : getMembers()) {
        if (!member || !sacrifice) return -1;
        if (member->isAlive() && sacrifice->isAlive()) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
                if(cowboy->shootSuccess(sacrifice)) count += 10;
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                if(ninja->slashSuccess(sacrifice)) count += 40;
            }
            if(!(sacrifice->isAlive())) sacrifice = findSacrifice(enemys);
        }
    }
    return count;
}

// int SmartTeam::stillAlive() const
// {
//     int numAlive = 0;
//     for(Character* member : members)
//     {
//         if(member->isAlive()) numAlive++;
//     }
//     return numAlive;
// }

// void SmartTeam::print() const
// {
//     for(Character* member : members)
//     {
//         cout << member->print() <<endl;
//     }
// }
