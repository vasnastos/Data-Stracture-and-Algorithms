/*
Να κατασκευαστεί πρόγραμμα το οποίο θα δέχεται από ένα αρχείο δεδομένα για φορτία(cargos.txt,[name,serial,cost]) και μέσω συνάρτησης 
να εμφανίζει τα τρία φορτία με το μικρότερο κόστος,να αυξάνει την τιμή τους κατά 5% και να ενημερώνει το αρχείο 
με τις νέες τιμές.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
#define TOP 3

std::string save="";

class cargo
{
    std::string name;
    std::string serial;
    double cost;
    public:
      cargo(std::string n,std::string s,double c)
      {
          name=n;
          serial=s;
          cost=c;
      }
      std::string get_name()const {return this->name;}
      std::string get_serial()const {return this->serial;}
      double get_cost()const {return this->cost;}
      void increase(int pr)
      {
          this->cost+=this->cost*pr/100.0;
      }
      friend std::ostream &operator<<(std::ostream &os,const cargo &c)
      {
          os<<"Name:"<<c.name<<"   Serial:"<<c.serial<<"   Cost:"<<c.cost;
          return os;
      }
};

class mycomparator
{
    public:
     bool operator()(const cargo &c1,const cargo &c2)
     {
         return c1.get_cost()<c2.get_cost();
     }
};

void read_data(std::vector <cargo> &vec)
{
    std::ifstream is;
    is.open("cargos.txt",std::ios::in);
    std::string line,word;
    std::vector <std::string> data;
    while(std::getline(is,line))
    {
        if(line.size()==0)
        {
            save+="\n";
            continue;
        }
        if(line.at(0)=='#')
        {
            save+=line+="\n";
            continue;
        }
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        if(data.size()!=3) continue;
        cargo c1(data[0],data[1],std::stod(data[2]));
        vec.push_back(c1);
    }
    is.close();
}

void get_Minimum(std::vector <cargo> &data)
{
    std::vector <cargo> crgs;
   std::priority_queue <cargo,std::vector <cargo>,mycomparator> pq;
   for(auto &x:data)
   {
       pq.push(x);
   }
   for(int i=0;i<TOP;i++)
   {
       crgs.push_back(pq.top());
       pq.pop();
   }
   std::cout.precision(4);
   std::ostream_iterator <cargo> output(std::cout,"\n");
   std::copy(crgs.begin(),crgs.end(),output);
   for(std::vector <cargo>::iterator itr=crgs.begin();itr!=crgs.end();itr++)
   {
       for(auto &x:data)
       {
           if(itr->get_serial()==x.get_serial())
           {
               x.increase(5);
           }
       }
   }
}

void reinformed_datasheet(std::vector <cargo> &data)
{
    std::ofstream os;
    os.open("cargos.txt",std::ios::app);
    os<<std::endl;
    os<<"Renew Data at:"<<__DATE__<<"----"<<__TIME__<<std::endl;
    os<<"*********************************************************"<<std::endl;
    for(auto itr=data.begin();itr!=data.end();itr++)
    {
        os<<*itr<<std::endl;
    }
    os<<"**********************************************************"<<std::endl;
}

int main()
{
    std::vector <cargo> cargos;
    read_data(cargos);
    get_Minimum(cargos);
    reinformed_datasheet(cargos);
    return 0;
}