/*
Aναδρομική έκδοση του κώδικα για την ταξινόμηση με επιλογή (selection sort).
COMPILING:g++ selection sort(recursive version).cpp -l comdlg32 -o run
EXECUTION:run
*/


#include <iostream>
#include <fstream>
#include <random>
#include <windows.h>
template <class T>void recursive_selection_sort(T *a,int i,int n)
{
    if(i==n) return;
    T min=a[i];
    int pos=i;
    for(int j=i+1;j<n;j++)
    {
       if(a[j]<min)
       {
           min=a[j];
           pos=j;
       }
    }
    T temp=a[i];
    a[i]=min;
    a[pos]=temp;
    recursive_selection_sort(a,i+1,n);
}

int main()
{
    std::mt19937 mt(RAND_MAX);
    std::uniform_int_distribution <int> produceintegers(1,50);
    std::uniform_real_distribution <double> producefloats(1.0,50.0);
    int tableint[10];
    double tablefloat[10];
    for(int i=0;i<10;i++)
    {
        tableint[i]=produceintegers(mt);
        tablefloat[i]=producefloats(mt);
    }
    recursive_selection_sort(tableint,0,10);
    recursive_selection_sort(tablefloat,0,10);
    std::ofstream out;
    std::string fn="results.out";
    out.open(fn);
    out<<"************* SORTED TABLES RESULT *********************"<<std::endl;
    out<<"               Table of Integers"<<std::endl;
    for(auto itr=tableint;itr!=tableint+sizeof(tableint)/sizeof(tableint[0]);itr++)
    {
        out<<"TableInt["<<itr-tableint<<"]:"<<*itr<<std::endl;
    }
    out<<std::endl;
    out<<"               Table of Floats"<<std::endl;
    for(int i=0;i<sizeof(tablefloat)/sizeof(tablefloat[0]);i++)
    {
        out<<"TableFloat["<<i<<"]:"<<*(tablefloat+i)<<std::endl;
    }
    out<<"*******************************************************"<<std::endl;
    char buffer[260];
    GetCurrentDirectory(260,buffer);
    std::cout<<"results have been printed at:"<<buffer<<"\\"<<fn<<std::endl;
    out.close();
}