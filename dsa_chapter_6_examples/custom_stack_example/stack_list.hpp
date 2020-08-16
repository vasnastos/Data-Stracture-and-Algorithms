#include <iostream>
template <class T>struct node
{
   T data;
   node *next;
};

template <class T>
class stacklist
{
    private:
      node <T> *head;
    public:
      stacklist();
      ~stacklist();
      bool is_empty();
      void push_front(T d);
      void erase_front();
      T front();
};