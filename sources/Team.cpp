#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>

#include "Team.hpp"
// #include "Team2.cpp"
// #include "SmartTeam.cpp"

using namespace std;
using namespace ariel;

Team::Team(Character* InitLeader):leader(InitLeader)
{
    if(InitLeader == nullptr) throw runtime_error("invalid leader value");
    if(InitLeader->getMember()) throw runtime_error("ERROR: already a member");
    InitLeader->setMember(true);
    members.push_back(InitLeader);
}

void Team::add(Character* other){

    if(other->getMember())  throw runtime_error("Error: already a team member");
    for (Character* member : members) {
        if (other == member) {
            throw runtime_error("Error: already a member");
        }
    }
    if (members.size() >= 10) throw runtime_error("ERROR: the team contains 10 members.");
    if(members.size() < 10)
    {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(other)) {
            members.insert(members.begin(),other);
        }
        else if (Ninja* ninja = dynamic_cast<Ninja*>(other)) {
            members.push_back(other);
        }
        other->setMember(true);   
    }
}

void Team::findLeader()
{
    Character* newLeader = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    double dis = 0;
    for(Character* member : members)
    {
        dis = member->distance(leader);
        if(member->isAlive() && dis < minDistance)
        {
            minDistance = dis;
            newLeader = member;
        }
    }
    this->leader = newLeader;
}

Character* Team::findSacrifice(Team* enemys)
{
    Character* sacrifice = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    double dis = 0;
    for(Character* member : enemys->getMembers())
    {
        dis = member->distance(leader);
        if(member->isAlive() && dis < minDistance)
        {
            minDistance = dis;
            sacrifice = member;
        }
    }
    return sacrifice;
}

void Team::attackSacrifice(Character *sacrifice, Team *enemys)
{
    for (Character* member : members) {
        if (member == nullptr || sacrifice == nullptr) return;
        if (member->isAlive() && sacrifice->isAlive()) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
                if(cowboy->hasboolets())cowboy->shoot(sacrifice);
                else cowboy->reload();
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                if(ninja->distance(sacrifice)<=1.0) ninja->slash(sacrifice);
                else ninja->move(sacrifice);
            }
            if(!(sacrifice->isAlive())) sacrifice = findSacrifice(enemys);
        }
    }
}

void Team::attack(Team* enemys)
{
    if(enemys == nullptr) throw std::invalid_argument("invalid enemys");
    if(enemys->stillAlive() == 0 || stillAlive() == 0) throw std::runtime_error("fight already ended");
    if (!leader) throw std::invalid_argument("ERROR: leader argument invalid");
    if(!leader->isAlive()) findLeader();
    if(!leader) return;
    Character* sacrifice = findSacrifice(enemys);
    if(!sacrifice) return;
    attackSacrifice(sacrifice, enemys);
}

int Team::stillAlive()
{
    int numAlive = 0;
    for(Character* member : getMembers())
    {
        if(member->isAlive()) numAlive++;
    }
    return numAlive;
}

void Team::print() const
{
    for(Character* member : members)
    {
        cout << member->print() <<endl;
    }
}
