#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#define SPACE 30

std::string select_file_name()
{
    int i;
    std::string fn="noname.csv";
    std::cout<<"1-players.csv"<<std::endl;
    std::cout<<"2-players2.csv"<<std::endl;
    std::cout<<"Select file:";
    std::cin>>i;
    if(i==1)
    {
       fn="players.csv";
    }
    else if(i==2)
    {
        fn="players2.csv";
    }
    return fn;
}

void read_data(std::map <std::string,int> &list)
{
    std::ifstream is;
    std::string line,fn,word;
    fn=select_file_name();
    is.open(fn);
    std::vector <std::string> data;
    if(!is.is_open())
    {
        std::cerr<<"No file opened"<<std::endl;
        return;
    }
    while(std::getline(is,line))
    {
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        list.insert(std::make_pair(data[0],std::stoi(data[1])));
    }
    is.close();
}

bool is_in(std::map <std::string,int> &src,std::string name)
{
    return src.find(name)!=src.end();
}

void modify(std::map <std::string,int> &src)
{
    std::string name;
    int score;
    for(int i=0;i<5;i++)
    {
        std::cout<<"Give player name:";
        std::cin>>name;
        if(!is_in(src,name))
        {
            std::cout<<"No such name found on the list"<<std::endl;
            continue;
        }
        std::cout<<"Give score:";
        std::cin>>score;
        src[name]+=score;
        std::cout<<"Score has been modified!!!!!!!"<<std::endl;
    }
}

void show_list(std::map <std::string,int> &src)
{
    std::cout<<"Players List"<<std::endl;
    int i=1;
    for(auto &kv:src)
    {
        std::cout<<i<<".";
        std::cout<<kv.first;
        for(int i=0;i<SPACE-kv.first.length();i++)
        {
            std::cout<<" ";
        }
        std::cout<<kv.second<<std::endl;
        i++;
    }
}

int main()
{
    std::map <std::string,int> list;
    read_data(list);
    show_list(list);
    modify(list);
    std::string name;
    int score;
    std::cout<<std::endl;
    std::cout<<"Insertion Form"<<std::endl;
    std::cout<<"Give Name"<<std::endl;
    std::cin>>name;
    std::cout<<"Give Score:";
    std::cin>>score;
    list[name]=score;
    show_list(list);
}