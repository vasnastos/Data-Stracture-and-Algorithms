#include <iostream>

template <class T>struct node
{
    T data;
    node *next;
};


template <class T> 
class queuelist
{
    private:
      node <T> *head;
    public:
     queuelist();
     ~queuelist();
     void push_back(T d);
     void popfront();
     bool isempty();
     T front();
     T back();
     int length();
};