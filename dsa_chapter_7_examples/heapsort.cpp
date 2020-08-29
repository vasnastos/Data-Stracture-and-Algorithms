#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <ostream>

/*
Ταξινόμιση σωρού.
  Εισαγωγή n στοιχείων πίνακα που πρέπει να ταξινομιθεί σε ένα σωρό.
  Eξαγωγή n-1 στοιχείων από τον σωρό για να πραγματοποιηθεί η αντίσοιχη ταξινίμιση.
*/

struct ram
{
    int capacity;
    double read;
    double write;
    bool operator>(const ram &rm)const {return capacity>rm.capacity;}
    void print()
    {
        std::cout<<capacity<<"---"<<read<<"MBps"<<"---"<<write<<"MBps"<<std::endl;
    }
};

class book
{
    std::string title;
    std::string author;
    double price;
    public:
       book(std::string t,std::string a,double p):title(t),author(a),price(p) {}
       bool operator>(const book &comp)const {return this->price>comp.price;}
       friend std::ostream &operator<<(std::ostream &os,const book &b1);
};

std::ostream &operator<<(std::ostream &os,const book &b1)
{
    os<<b1.author<<"--"<<b1.title<<"--"<<b1.price;
    return os;
}

template <class T>
class mycomparator
{
    public:
     bool operator()(T &e1,T &e2)
     {
         return e1>e2;
     }
};

template <class T>void heapsort(T *start,T *end)
{
     std::priority_queue <T,std::vector <T>,mycomparator <T>> pq;
     for(auto itr=start;itr!=end;itr++)
     {
         pq.push(*itr);
     }
     for(auto itr=start;itr!=end;itr++)
     {
         *itr=pq.top();
         pq.pop();
     }
}

int main()
{
    int a[10]={21,33,56,1,23,78,5,7,9,17};
    ram rams[3]={{8,625,625},{16,456,456},{32,321,321}};
    book books[3]={{"The Silent Patient","Alex Michaelides",9.38},{"Normal People","Sally Rooney",8.62},{"The Choice","Edith Eger",9.71}};
    heapsort(a,a+10);
    heapsort(rams,rams+3);
    heapsort(books,books+3);
    std::cout.precision(4);
    std::cout<<"Integers board after sort"<<std::endl;
    std::ostream_iterator <int> output(std::cout," ");
    std::copy(a,a+10,output);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Rams after sort"<<std::endl;
    for(int i=0;i<3;i++)
    {
        rams[i].print();
    }
    std::cout<<std::endl;
    std::cout<<"Books after sort"<<std::endl;
    for(int i=0;i<3;i++)
    {
        std::cout<<books[i]<<std::endl;
    }
}