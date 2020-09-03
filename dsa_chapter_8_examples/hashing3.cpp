#include <iostream>
#include <set>
#include <random>
#include <thread>
#include <algorithm>
#include <sstream>

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

size_t hash(std::string &key)
{
    size_t h=0;
    int j=1;
    for(int i=0;i<key.length();i++)
    {
        h=37*j+key.at(i);
        j++;
    }
    return h;
}

int main()
{
    int tab[20];
    int tablepos;
    std::set <int> positions;
    std::mt19937 mt(seed());
    std::default_random_engine en{};
    int collisions=0;
    int val;
    std::uniform_int_distribution <int> dist(1,9000);
    for(int i=0;i<20;i++)
    {
        int collisionscount=0;
        std::string hashstr="";
        for(int j=0;j<=i;j++)
        {
            hashstr+='A'+j;
        }
        val=hash(hashstr);
        tablepos=val%20;
        while(positions.find(tablepos)!=positions.end())
        {
            std::shuffle(hashstr.begin(),hashstr.end(),en);
            val=hash(hashstr);
            tablepos=val%20;
            collisionscount++;
        }
        positions.insert(tablepos);
        tab[tablepos]=dist(mt);
        collisions+=collisionscount;
        std::cout<<"#"<<val<<"->"<<tablepos<<"\t"<<tab[tablepos]<<std::endl;
        std::cout<<"Collision Count:"<<collisionscount<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout<<"Total Collisions:"<<collisions<<std::endl;
    std::cout<<"************** Board Summary *********************"<<std::endl;
    for(auto itr=tab;itr!=tab+20;itr++)
    {
        std::cout<<"Tab["<<itr-tab<<"]:"<<*itr<<std::endl;
    }
    std::cout<<"**************************************************"<<std::endl;
}