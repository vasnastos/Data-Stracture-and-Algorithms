/*
  Μετράει στοιχεία ανάλογα με μία συνθήκη η οποία ορίζεται μέσω lambda function.
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector <int> vec;
    for(int i=0;i<10;i++)
    {
      vec.push_back(i);
    }
    std::cout<<"Over 12:"<<std::count_if(vec.begin(),vec.end(),[](int &a) {return a>12;})<<std::endl;
}