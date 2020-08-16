#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//using namespace std;

int main(int argc,char **argv)
{
    std::vector <int> numbers;
    //Διάβασμα αριθμών από αρχείο numbers.txt
    std::ifstream ist;
    std::string line;
    ist.open("numbers.txt");
    int number;
    while(std::getline(ist,line))
    {
        std::stringstream ss(line);
        ss>>number;
        numbers.push_back(number);
    }
    ist.close();  
    std::cout<<"Numbers List::"<<std::endl;
    /*1os τρόπος   
    for(int i=0;i<numbers.size();i++)
    {
        std::cout<<"Element "<<i<<":"<<numbers.at(i)||numbers[i]<<std::endl;
    }*/
    
    /*2ος τρόπος
    int i=1;
    for(auto &x:numbers)
    {
        std::cout<<"Element "<<i<<":"<<x<<std::endl;
        i++;
    }*/
    //3ος τρόπος
    for(std::vector <int>::iterator itr=numbers.begin();itr!=numbers.end();itr++)
    {
        std::cout<<*itr<<std::endl;
    }
}