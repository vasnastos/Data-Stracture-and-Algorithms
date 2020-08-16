#include <iostream>

template <class T>struct node 
{
    T data;
    node *next;
    node *previous;
};

template <class T>
class double_linked_list
{
    private:
      node <T> *head;
      node <T> *tail;
    public:
      double_linked_list();
      double_linked_list(T d);  
      ~double_linked_list();
      int length();
      void push_back(T d);
      void push_front(T d);
      void insert(int pos,T d);
      void erase(int position);
      void erase_front();
      void popback();
      T front();
      T back();
      bool isEmpty();
      void printlist();
      void operator<<(T d);
};