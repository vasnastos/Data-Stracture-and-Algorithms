#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

struct student
{
   std::string id;
    std::string name;
    int semester;
    std::string direc;
    double grade;
};

void printlist(std::list <student> &s)
{
   for(std::list <student>::iterator itr=s.begin();itr!=s.end();itr++)
   {
        std::cout<<itr->id<<"--"<<itr->name<<"--"<<itr->semester<<"--"<<itr->direc<<"--"<<itr->grade<<std::endl;
   } 
   std::cout<<std::endl;
}

int main()
{
    std::list <student> mylist;
    std::vector <std::string> data;
    std::string line,word;
    std::ifstream fin;
    fin.open("students.txt",std::ios::in);
    while(std::getline(fin,line))
    {
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,'-'))
        {
            data.push_back(word);
        }
        if(data.size()!=5) continue;
        student s{data[0],data[1],std::stoi(data[2]),data[3],std::stod(data[4])};
        mylist.push_back(s);
    }
    std::cout<<"1ST CHECK"<<std::endl;
    printlist(mylist);
    std::cout<<"2ND CHECK"<<std::endl;
    student ns{"011","iasonas",3,"CS",7.0};
    mylist.push_front(ns);
    printlist(mylist);
    std::cout<<"3RD CHECK"<<std::endl;
     student ns1{"012","electra",5,"CE",6.0};
     mylist.push_back(ns1);
     printlist(mylist);
    std::cout<<"4TH CHECK"<<std::endl;
    mylist.remove_if([](const student &s) {return s.grade<5.0;});
    printlist(mylist);
    return 0;
}