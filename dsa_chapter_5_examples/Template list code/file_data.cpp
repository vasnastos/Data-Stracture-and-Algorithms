#include "template_list.cpp"
#include <fstream>
#include <sstream>

template <class T>void read_data(list <T> &ll,int op)
{
    std::string line,fn;
    if(op==1)
    {
        fn="integers.txt";
    }
    else if(op==2)
    {
        fn="floats.txt";
    }
    std::ifstream ifstr;
    ifstr.open(fn);
    if(!ifstr.is_open())
    {
        std::cerr<<"File did not found"<<std::endl;
        return;
    }
    T number;
    while(std::getline(ifstr,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        ss>>number;
        /*       Εναλλακτικά
            if(line.at(0)=='#') continue;
            if(line.size()==0) continue;
            number=std::stoi(line)//stod(line) αν γνωρίζω τον τύπο δεδομένων.
        */
       ll.push_back(number);
    }
    ifstr.close();
}