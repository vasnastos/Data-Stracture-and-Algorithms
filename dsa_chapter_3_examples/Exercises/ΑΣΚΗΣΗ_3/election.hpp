#include <iostream>
class election
{
    std::string name;
    size_t votes;
    public:
     election(std::string n,size_t v);
     size_t get_votes()const;
     std::string get_name()const;
     friend std::ostream &operator<<(std::ostream &os,const election &el);
};