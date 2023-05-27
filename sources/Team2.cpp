#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>

#include "Team2.hpp"
using namespace std;
using namespace ariel;


// team2 functions
void Team2::add(Character* other)
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