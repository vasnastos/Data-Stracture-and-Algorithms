/*
Να υλοποιηθεί η δομή της στοίβας χρησιμοποιώντας αντικείμενα ουράς (std::queue) και τις λειτουργίες που επιτρέπονται σε αυτά. Υλοποιήστε τις λειτουργίες 
της στοίβας empty(), size(), push(), pop() και top().
*/
#include <iostream>
#include <queue>

template <class T>
class stack
{
    std::queue <T> firstqueue;
    std::queue <T> custom;
    void reverse()
    {
        while(!custom.empty())
        {
            custom.pop();
        }
        T helpboard[firstqueue.size()];
        int size=firstqueue.size();
        if(size==1)
        {
            custom.push(firstqueue.front());
            return;
        }
        int i=firstqueue.size()-1;
        while(!firstqueue.empty())
        {
            helpboard[i]=firstqueue.front();
            firstqueue.pop();
            i--;
        }
        for(int i=size-1;i>=0;i--)
        {
            custom.push(helpboard[i]);
        }
        for(int j=0;j>size;j++)
        {
            firstqueue.push(helpboard[j]);
        }
    }
    public:
      stack() {}
      ~stack() {}
      bool empty() {return custom.empty();}
      int size() {return custom.size();}
      void push(T d)
      {
          firstqueue.push(d);
          this->reverse();
      }
      void pop()
      {
          custom.pop();
      }
      T top()
      {
          return custom.front();
      }
}; 

int main()
{
    stack <int> mystack;
    for(int i=1;i<10;i++)
    {
        mystack.push(i);
    }
    std::cout<<"Size:"<<mystack.size()<<std::endl;
    std::cout<<"Top:"<<mystack.top()<<std::endl;
    while(!mystack.empty())
    {
        std::cout<<mystack.top()<<std::endl;
        mystack.pop();
    }
}
