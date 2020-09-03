/*
Γράψτε μια συνάρτηση που να δέχεται έναν πίνακα ακεραίων Α και έναν ακέραιο αριθμό sum και να βρίσκει το πλήθος
από όλα τα ζεύγη τιμών του Α που το άθροισμά τους είναι ίσο με sum.Στην κύρια συνάρτηση να πραγματοποιηθεί τοποθέτη
ση 10 τυχαίων αριθμών σε πίνακα(εύρους 1,200) με χρήση συνάρτησης κατακερματισμού.
*/
#include <iostream>
#include <set>
#include <thread>
#include <vector>
#include <random>
#define HT_SIZE 10

size_t hash(int &num)
{
    std::string helpstring="";
    int helpnumber=num;
    while(helpnumber!=0)
    {
        helpstring+='A'+(helpnumber%8);
        helpnumber/=8;
    }
    int j=1;
    size_t h=0;
    for(int i=0;i<helpstring.length();i++)
    {
       h+=helpstring.at(i)*j;
       j*=2;
    }
    return h;
}

std::vector <std::pair <int,int>> count_by_sum(int *a,int size,int sum)
{
    std::vector <std::pair<int,int>> pairs;
   for(int i=0;i<size;i++)
   {
      for(int j=0;j<size;j++)
      {
          if(i==j) continue;
          if(a[i]+a[j]==sum)
          {
              std::pair <int,int> p1=std::make_pair(i,j);
              bool f=false;
              for(auto itr=pairs.begin();itr!=pairs.end();itr++)
              {
                  if((itr->first==p1.first && itr->second==p1.second) || (itr->first==p1.second && itr->second==p1.first))
                  {
                      f=true;
                      break;
                  }
              }
              if(f)
              {
                  continue;
              }
              pairs.push_back(p1);
          }
      }
   }
   return pairs;
}

int main()
{
   std::mt19937 mt(1452);
   std::uniform_int_distribution <int> dist(0,200);
   std::set <int> positions;
   int collisions=0;
   int numbers[HT_SIZE];
   int number;
   for(int i=0;i<10;i++)
   {
       int collisioncount=0;
      number=dist(mt);
      int tablepos=hash(number)%HT_SIZE;
      while(positions.find(tablepos)!=positions.end())
      {
          collisioncount++;
          tablepos++;
          if(tablepos==10)
          {
              tablepos=0;
          }
      } 
      positions.insert(tablepos);
      numbers[tablepos]=number;
      collisions+=collisioncount;
      std::cout<<"#"<<tablepos<<"->"<<"Numbers["<<tablepos<<"]:"<<numbers[tablepos]<<"\tTotal collisions:"<<collisioncount<<std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(3));
   }
   std::cout<<"Total collisions made on the value hashing insertion:"<<collisions<<std::endl;
   std::vector <std::pair<int,int>> prs=count_by_sum(numbers,HT_SIZE,296);
   std::cout<<"Total pairs with summary equal to 296::"<<prs.size()<<std::endl;
   std::cout<<"Position of pairs with summary equal to 296 are:::"<<std::endl;
   for(std::vector <std::pair<int,int>>::iterator itr=prs.begin();itr!=prs.end();itr++)
   {
       std::cout<<"("<<itr->first<<","<<itr->second<<")"<<std::endl;
   }
   return 0;
}