#include "queuelist.hpp"

template <class T>queuelist<T>::queuelist() {this->head=nullptr;}

template <class T>queuelist<T>::~queuelist()
{
    while(this->head!=nullptr)
    {
        node <T> *delnode=this->head;
        this->head=this->head->next;
        delete delnode;
    }
}

template <class T>void queuelist<T>::push_back(T d)
{
    if(this->head==nullptr)
    {
        this->head=new node <T>{d,nullptr};
        return;
    }
    node <T> *curr=this->head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    node <T> *newnode=new node <T>{d,nullptr};
    curr->next=newnode;
}

template <class T>void queuelist<T>::popfront()
{
    node <T> *delnode=this->head;
    this->head=this->head->next;
    delete delnode;
}

template <class T>T queuelist <T>::front() {return this->head->data;}

template <class T>bool queuelist<T>::isempty() {return this->head==nullptr;}

template <class T>int queuelist<T>::length()
{
    int len=0;
    node <T> *curr=this->head;
    while(curr!=nullptr)
    {
        len++;
        curr=curr->next;
    }
    return len;
}

template <class T>T queuelist<T>::back()
{
    node <T> *curr=this->head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    return curr->data;
}