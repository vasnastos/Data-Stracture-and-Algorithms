#include <list>
#include <iostream>
#include <ostream>
#include <iterator>

template <class T>void printlist(std::list <T> &alist)
{
    std::ostream_iterator <T> output(std::cout," ");
    std::cout<<"List::";
    std::copy(alist.begin(),alist.end(),output);
    std::cout<<std::endl;
    std::cout<<"Counted list elements:"<<alist.size()<<std::endl;
}

int main()
{
    std::list <int> mylist;
    
    //Τοποθέτηση των αριθμών 1-8 στην λίστα.
    for(int i=1;i<8;i++)
    {
        mylist.push_back(i);
    }
    printlist(mylist);

    //Εισαγωγή στην αρχή της λιστάς του αριθμού 10.
    mylist.push_front(10);
    printlist(mylist);

    //Τοποθέτηση του στοιχείου 48 στην πέμπτη θέση της λίστας.
    std::list <int>::iterator itr=mylist.begin();
    for(int i=0;i<4;i++)
    {
      itr++;
    }
    mylist.insert(itr,48);
    printlist(mylist);

    //Διαγραφή του τελευταίου στοιχείου της λίστας.
    mylist.pop_back();
    printlist(mylist);

    //Εκτύπωση λίστας και πρώτου στοιχείου
    printlist(mylist);
    std::cout<<"Front element:"<<mylist.front()<<std::endl;

    //Διαγραφή στοιχείου από συγκεκριμένη θέση
    int pos;
    std::cout<<"Give position you want to erase:";
    std::cin>>pos;
    if(pos<0 || pos>mylist.size())
    {
        std::cout<<"you are trying to delete an invalid position"<<std::endl;
    }
    else
    {
        std::list <int>::iterator itrdel=mylist.begin();
        for(int i=0;i<pos;i++)
        {
            itrdel++;
        }
        mylist.erase(itrdel);
    }
    printlist(mylist);

    //Παρουσίαση ανάποδης λίστας
    mylist.reverse();
    printlist(mylist);
    std::cout<<"Front Element:"<<mylist.front()<<std::endl;

    //Εκτύπωση της λίστας ανάποδα
    printlist(mylist);
    std::cout<<std::endl;
    std::cout<<"        REVERSE LIST    "<<std::endl;
    for(auto itr=mylist.rbegin();itr!=mylist.rend();itr++)
    {
        std::cout<<*itr<<" ";
    } 
    std::cout<<std::endl;


}