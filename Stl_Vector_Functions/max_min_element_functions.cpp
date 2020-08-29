/*
Συναρτήσεις που ανήκουν στην βιβλιοθήκη algorithm υπολογίζουν το μέγιστο και το ελάχιστο στοιχείο.
Επιστρέφουν τις θέσεις μνήμης του μέγιστου και του ελάχιστου στοιχείου.
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector <int> vec;
    for(int i=1;i<10;i++)
    {
        vec.push_back(i);
    }
    std::cout<<"Max:"<<*std::max_element(vec.begin(),vec.end())<<std::endl;
    std::cout<<"Min:"<<*std::min_element(vec.begin(),vec.end())<<std::endl;
    return 0;
}