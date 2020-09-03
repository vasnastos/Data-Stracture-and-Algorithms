#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

int main()
{
    std::unordered_map <std::string,double> recs;
    std::ifstream is;
    std::cout<<"****************** Raw data from file ***************************"<<std::endl;
    is.open("operating_systems.txt");
    std::string line;
    std::vector <std::string> data;
    std::string word;
    while(std::getline(is,line))
    {
        std::stringstream ss(line);
        data.clear();
        while(std::getline(ss,word,'-'))
        {
           data.push_back(word);
        }
        if(data.size()!=2) continue;
        std::pair <std::string,double> p1;
        p1=std::make_pair(data[0],std::stod(data[1]));
        recs.insert(p1);
        std::cout<<line<<std::endl;
    }
    is.close();
    std::cout<<"*****************************************************************"<<std::endl<<std::endl;
    std::cout<<"######################### Table summary:::: #####################"<<std::endl;
    for(auto &op:recs)
    {
        std::cout<<op.first<<"---"<<op.second<<std::endl;
    }
    std::cout<<"#################################################################"<<std::endl<<std::endl;
    std::string op;
    std::cout<<"Search for an operating system:";
    std::cin>>op;
    if(recs.find(op)!=recs.end())
    {
        std::cout<<"Percentance of usage:"<<recs[op]<<std::endl;
    }
    else 
    {
        std::cerr<<"Element does not exist on the list!!!!!"<<std::endl;
    }
}