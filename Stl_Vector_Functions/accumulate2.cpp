/*
Όταν η συνάρτηση accumulate καλείται για στοιχεία τύπου μίας δομής η μίας κλάσης
χρειάζεται να οριστεί και η κατάλληλη συνάρτηση που θα καθορίσει πως θα πραγματοποιηθεί η πρόσθεση των στοιχείων.
*/
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct department
{
    std::string empid;
    double salary;
};

double summary(double sum,department &d)
{
    return sum+d.salary;
}

double average(std::vector <department> &dep)
{
    return std::accumulate(dep.begin(),dep.end(),0.0,summary)/dep.size();
}

int main()
{
    std::vector <department> depin;
    for(int i=1;i<10;i++)
    {
        department d;
        d.empid="emp"+std::to_string(i);
        d.salary=500+i*50.0;
        depin.push_back(d);
    }
    std::cout<<"Average:"<<average(depin)<<std::endl;
    return 0;
}