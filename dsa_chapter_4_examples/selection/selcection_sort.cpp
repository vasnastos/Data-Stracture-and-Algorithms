/*
Να υλοποιηθεί ο αλγόριθμος ταξινόμησης με επιλογή (selection sort) και να εφαρμοστεί για τη ταξινόμηση ενός πίνακα
πραγματικών τιμών, ενός πίνακα ακεραίων και ενός πίνακα με λεκτικά (δηλαδή να γίνουν τρεις κλήσεις του αλγορίθμου).
Ο αλγόριθμος ταξινόμησης με επιλογή ξεκινά εντοπίζοντας το μικρότερο στοιχείο και το τοποθετεί στη πρώτη θέση.
Συνεχίζει, ακολουθώντας την ίδια διαδικασία χρησιμοποιώντας το τμήμα του πίνακα που δεν έχει ταξινομηθεί ακόμα
*/
#include <iostream>
#include <random>
#include <fstream>
#include <typeinfo>
template <class T>void selection_sort(T *board,int n)
{
    int choice;
    while(true)
    {
        std::cout<<"1-Sort from min to max element for "<<typeid(*board).name()<<" board"<<std::endl;
        std::cout<<"2-Sort from max to min element for "<<typeid(*board).name()<<" board"<<std::endl;
        std::cout<<"Give choice:";
        std::cin>>choice;
        if(choice!=1 && choice!=2)
        {
            continue;
        }
        else break;
    }
    if(choice==1)
    {
        T min;
        int pos;
        for(int i=0;i<n;i++)
        {
           min=board[i];
           pos=i;
           for(int j=i+1;j<n;j++)
           {
              if(board[j]<min)
              {
                 min=board[j];
                 pos=j;
              }
           }
           T temp=board[i];
           board[i]=min;
           board[pos]=temp;
        }
    }
    else
    {
        T max;
        int pos;
        for(int i=0;i<n;i++)
        {
           max=board[i];
           pos=i;
           for(int j=i+1;j<n;j++)
           {
              if(board[j]>max)
              {
                 max=board[j];
                 pos=j;
              }
           }
           T temp=board[i];
           board[i]=max;
           board[pos]=temp;
        }
    }   
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
    selection_sort(tableint,10);
    selection_sort(tablefloat,10);
    std::ofstream out;
    out.open("results.out");
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
    out.close();
}