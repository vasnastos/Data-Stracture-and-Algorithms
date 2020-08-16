#include "stack_list.hpp"

template <class T> stacklist<T>::stacklist() {head=nullptr;}

template <class T>stacklist<T>::~stacklist()
{
    while(this->head!=nullptr)
    {
        node <T> *delnode=this->head;
        this->head=this->head->next;
        delete delnode;
    }
}


template <class T>void stacklist<T>::push_front(T d)
{
    if(this->head==nullptr)
    {
        this->head=new node<T>{d,nullptr};
        return;
    }
     node <T> *newnode=new node<T>{d,nullptr};
     newnode->next=this->head;
     this->head=newnode;
}

template <class T>void stacklist<T>::erase_front()
{
    node <T> *delnode=this->head;
    this->head=this->head->next;
    delete delnode;
}

template <class T>T stacklist<T>::front() {return this->head->data;}

template <class T>bool stacklist<T>::is_empty() {return this->head==nullptr;}