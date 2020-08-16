#include "election.hpp"

election::election(std::string n,size_t v):name(n),votes(v) {}
std::string election::get_name()const {return this->name;}
size_t election::get_votes()const {return this->votes;}
std::ostream &operator<<(std::ostream &os,const election &e)
{
    os<<"Party:"<<e.name<<"\tVotes:"<<e.votes;
    return os;
}