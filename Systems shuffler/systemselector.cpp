#include "numbers_struct.cpp"
#include <string>
#include <numeric>
#include <algorithm>
#include <map>

std::uniform_int_distribution <int> sys(2,16);

number numberproduction()
{
    int system;
    std::string anumber="";
    system=sys(mt);
    std::uniform_int_distribution <int> digit(0,system-1);
    int adigit;
    for(int i=0;i<8;i++)
    {
       adigit=digit(mt);
       if(adigit>9)
       {
          anumber+=symbols[adigit-10];
       }
       else
       {
           anumber+=std::to_string(adigit);
       } 
    }
    return number{system,anumber};
}

int sum(int s,const number &n)
{
    return s+toDecimal(n);
}

int summary()
{
    return std::accumulate(numbers.begin(),numbers.end(),0,sum);
}

std::map <int,int> count_occurences()
{
    std::map <int,int> occs;
    for(int i=2;i<=16;i++)
    {
       occs[i]=0;
    }
    for(auto i=numbers.begin();i!=numbers.end();i++)
    {
        occs[i->system]++;
    }
    return occs;
}

double random_fill()
{
    std::uniform_int_distribution <int> pl(3,50000);
    int countsummary=pl(mt);
    std::cout<<countsummary<<std::endl;
    std::chrono::high_resolution_clock::time_point t1=std::chrono::high_resolution_clock::now();
    for(int i=0;i<countsummary;i++)
    {
        numbers.push_back(numberproduction());
        numbers.sort();
    }
    std::chrono::high_resolution_clock::time_point t2=std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> dur=std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
    return dur.count();
}

const int amount=numbers.size();

double percent(int val)
{
    return ((val*1.0)/amount)*100.0;
}

void show()
{
    double time=random_fill();
    std::cout<<"\tRandom numbers from 14 systems producer"<<std::endl;
    std::cout<<"\t\tNumbers List"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
    std::cout<<"\t\tSystem\tNumber"<<std::endl;
    for(std::list <number>::iterator itr=numbers.begin();itr!=numbers.end();itr++)
    {
        std::cout<<"\t\t  "<<itr->system;
        if(itr->system>=10)
        {
            std::cout<<"  ";
        }
        else
        {
            std::cout<<"   ";
        }
        std::cout<<"\t"<<itr->num<<std::endl;
    }
    std::cout<<"-----------------------------------------------"<<std::endl<<std::endl;
    std::cout<<"\t\tInformation"<<std::endl;
    std::cout<<"Time Elapsed:"<<time<<" ms"<<std::endl;
    std::cout<<"Total numbers Produced:"<<numbers.size()<<std::endl;
    std::cout<<"Numbers Summary:"<<summary()<<std::endl;
    std::cout<<"\t\tOccurences"<<std::endl;
    std::cout<<"***************************************************"<<std::endl;
    std::map <int,int> occs=count_occurences();
    std::cout<<"\t\tSystem\tOccurences\tPrecent"<<std::endl;
    for(auto &oc:occs)
    {
       std::cout<<"\t\t  "<<oc.first;
       if(oc.first>10)
       {
           std::cout<<"  ";
       }
       else
       {
           std::cout<<"   ";
       }
       std::cout<<"\t   "<<oc.second<<"     \t"<<percent(oc.second)<<"%%"<<std::endl;
    }
    std::cout<<"***************************************************"<<std::endl;
}