/*
Στον παρακάτω κώδικα πραγματοποιήται η εισαγωγή τιμών από αρχείο με τυχαίο αριθμό τιμών σε ενά πίνακα με χρήση 
συνάρτησης κατακερματισμού.
Θα χρησιμοποιηθεί η έτοιμη συνάρτηση κατακερματισμού που παρέχει η STL.
*/


#include <iostream>
#include <set>
#include <random>
#include <sstream>
#include <fstream>

int main()
{
    int *a;
    std::set <int> positions;
    std::hash <int> myhash;
    std::ifstream is;
    std::string line;
    std::mt19937 mt(1821);
    std::uniform_int_distribution <int> dist(1,2000);
    is.open("numbers.txt",std::ios::in);
    int number;
    int counter=0;
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        counter++;
    }
    is.close();
    a=new int[counter];
    is.open("numbers.txt");
    int collisions=0;
    while(std::getline(is,line))
    {
        int collisionscount=0;
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        ss>>number;
        int tablepos=myhash(number)%counter;
        while(positions.find(tablepos)!=positions.end())
        {
            tablepos=myhash(number+dist(mt))%counter;
            collisionscount++;
        }
        positions.insert(tablepos);
        a[tablepos]=number;
        std::cout<<"a["<<tablepos<<"]  as "<<a[tablepos]<<std::endl;
        std::cout<<"Collisions made:"<<collisionscount<<std::endl<<std::endl;
        collisions+=collisionscount;
    }
    is.close();
    std::cout<<"Board Summary::::"<<std::endl;
    for(auto itr=a;itr!=a+counter;itr++)
    {
        std::cout<<"a["<<itr-a<<"]:"<<*itr<<std::endl;
    }
    delete []a;
    return 0;
}
