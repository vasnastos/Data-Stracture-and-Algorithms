/*
Ο αλγόριθμος bogosort αναδιατάσσει τυχαία τις τιμές ενός πίνακα μέχρι να προκύψει μια ταξινομημένη διάταξη. Γράψτε
ένα πρόγραμμα που να υλοποιεί τον αλγόριθμο bogosort για την ταξινόμηση ενός πίνακα ακεραίων τιμών. Χρησιμοποιήστε τη συνάρτηση shuffle.
*/

#include <iostream>
#include <random>
#include <algorithm>

template <class T>std::vector <T> get_sorted_table(T *a,int n)
{
    std::vector <T> sorted;
    for(int i=0;i<n;i++)
    {
        sorted.push_back(a[i]);
    }
    sort(sorted.begin(),sorted.end());
    return sorted;
}

template <class T>bool is_sorted(T *b,int N)
{
   std::vector <T> sorted=get_sorted_table(b,N);
   int cnt=0;
   for(int i=0;i<N;i++)
   {
       if(b[i]==sorted[i])
       {
           cnt++;
       }
   }
   return cnt==N;
}

template <class T>int bogosort(T *a,int n)
{
    std::default_random_engine en{};
    int i=0;
    while(!is_sorted(a,n))
    {
        i++;
        shuffle(a,a+n,en);
    }
    return i;
}

int main()
{
    int a[]={14,5,1,6,8,11,21,2};
    int p=bogosort(a,sizeof(a)/sizeof(a[0]));
    std::cout<<"Bogosort"<<std::endl;
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        std::cout<<"a["<<i<<"]:"<<a[i]<<std::endl;
    }
    std::cout<<"Execute algorithm "<<p<<" times"<<std::endl;
    return 0;
}