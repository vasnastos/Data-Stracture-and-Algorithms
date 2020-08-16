/*
Να υλοποιηθεί η δομή της ουράς χρησιμοποιώντας αντικείμενα στοίβας (std::stack) και τις λειτουργίες που επιτρέπονται
σε αυτά. Υλοποιήστε τις λειτουργίες της ουράς empty(), size(), enqueue(), dequeue() και front().
*/
#include <iostream>
#include <stack>
template <class T>
class queue
{
    std::stack <T> firststack;
    std::stack <T> custom;
    void reverse()
    {
        while(!custom.empty())
        {
            custom.pop();
        }
        T helpboard[firststack.size()];
        int size=firststack.size();
        if(size==1)
        {
            custom.push(firststack.top());
            return;
        }
        int i=size-1;
        while(!firststack.empty())
        {
            helpboard[i]=firststack.top();
            firststack.pop();
            i--;
        }
        // 1 2
        for(int j=size-1;j>=0;j--)
        {
            custom.push(helpboard[j]);
        }
        for(int j=size-1;j>=0;j--)
        {
            firststack.push(helpboard[j]);
        }
    }
    public:
       queue() {}
       ~queue() {while(!firststack.empty()) {firststack.pop();}}
       bool empty() {return custom.empty();}
       int size() {return custom.size();}
       T front() {return custom.top();}
       void enqueue(T *data,int size)
       {
           if(size==1)
           {
               firststack.push(*data);
           }
           else
           {
               for(int i=0;i<size;i++)
               {
                   firststack.push(*(data+i));
               }
           }
           this->reverse();
       }
       void dequeue(int pos)
       {
           if(pos>custom.size())
           {
               pos=custom.size();
           }
           for(int i=0;i<pos;i++)
           {
               custom.pop();
           }
       }
};

int main()
{
    queue <int> myqueue;
    int data[10];
    for(int i=1;i<=10;i++)
    {
       data[i-1]=i;
    }
    myqueue.enqueue(data,10);
    std::cout<<"Size:"<<myqueue.size()<<std::endl;
    std::cout<<"Front:"<<myqueue.front()<<std::endl;
    while(!myqueue.empty())
    {
        std::cout<<"Front:"<<myqueue.front()<<std::endl;
        myqueue.dequeue(1);
    }
}