#include "driver.hpp"

int sum(int s,election &elec)
{
    return s+elec.get_votes();
}

void open_file(std::vector <election> &elc)
{
    std::string fn="elections.txt";
    std::ifstream is;
    std::string line,word;
    is.open(fn,std::ios::in);
    std::vector <std::string> data;
    while(std::getline(is,line))
    {
        data.clear();
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        if(data.size()!=2) continue;
        election el(data[0],std::stoll(data[1]));
        elc.push_back(el);
    }
    is.close();
}

size_t calculate_total(std::vector <election> &el)
{
    return std::accumulate(el.begin(),el.end(),0,sum);
}

std::map <std::string,double> precents(std::vector <election> &el)
{
    std::map <std::string,double> res;
    int total=calculate_total(el);
    for(int i=0;i<el.size();i++)
    {
        double precent=((el[i].get_votes()*1.0)/total)*100.0;
        res.insert(std::make_pair(el[i].get_name(),precent));
    }
    return res;
}