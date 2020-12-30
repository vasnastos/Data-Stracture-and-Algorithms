#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <list>
#include <queue>
#include <cmath>
struct number;

long seed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::string symbols[6]={"A","B","C","D","E","F"};

int find_numeric(char c)
{
    switch(c)
    {
        case 'A':
          return 10;
        case 'B':
          return 11;
        case 'C':
          return 12;
        case 'D':
          return 13;
        case 'E':
          return 14;
        case 'F':
          return 15;
        default:
          return -1;
    }
}

int toDecimal(const number &n);

struct number
{
    int system;
    std::string num;
    bool operator<(const number &n)const 
    {
        return toDecimal(*this)<toDecimal(n);
    }
};

int toDecimal(const number &n)
{
   std::queue <int> q;
   for(char c:n.num)
   {
       q.push(c);
   }
   int value=std::pow(n.system,n.num.length()-1);
   int summary=0;
   while(!q.empty())
   {
       if(q.front()>='A' && q.front()<='F')
       {
           summary+=find_numeric(q.front())*value;
       }
       else
       {
           summary+=q.front()*value;
       }
       value/=n.system;
       q.pop();
   }
   return summary;
}

std::list <number> numbers;
