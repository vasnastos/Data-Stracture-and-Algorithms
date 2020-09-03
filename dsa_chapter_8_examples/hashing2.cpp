#include <iostream>
#include <set>
#include <thread>
#include <algorithm>
#include <random>

size_t hash(std::string key)
{
   size_t h=0;
   int j=1;
   for(int i=0;i<key.length();i++)
   {
       h+=key.at(i)*j;
       j*=2;
   }
   return h;
}

int main()
{
    std::string board[10];
    char letters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int tablepos=-1;
    std::mt19937 mt(1821);
    std::default_random_engine en{};
    std::set <int> positions;
    std::uniform_int_distribution <int> dist(6,10);
    std::uniform_int_distribution <int> lets(0,25);
    int totalcols=0;
    for(int i=0;i<10;i++)
    {
        int collisioncount=0;
        int value=dist(mt);
        std::string pr="";
        int val;
        for(int i=0;i<value;i++)
        {
            pr+=letters[lets(mt)];
        }
        val=hash(pr);
        tablepos=val%10;
        while(positions.find(tablepos)!=positions.end())
        {
            collisioncount++;
            std::string nv=pr;
           std::shuffle(nv.begin(),nv.end(),en);
           val=hash(nv);
           tablepos=val%10;
        }
        totalcols+=collisioncount;
        positions.insert(tablepos);
        board[tablepos]=pr;
        std::cout<<"************** "<<i+1<<" insertion of random string *********************"<<std::endl;
        std::cout<<"#"<<val<<"->"<<tablepos<<"\tBoard["<<tablepos<<"]:"<<board[tablepos]<<std::endl;
        std::cout<<"Collisions made:"<<collisioncount<<std::endl;
        std::cout<<"*************************************************************************"<<std::endl<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout<<"Total collisions:"<<totalcols<<std::endl;
    std::cout<<"Board summary::::::"<<std::endl;
    for(std::string* itr=board;itr!=board+10;itr++)
    {
        std::cout<<"Board["<<itr-board<<"]:"<<*itr<<std::endl;
    }
}