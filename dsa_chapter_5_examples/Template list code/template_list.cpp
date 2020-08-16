/*
Υλοποιήση των συναρτήσεων μελών της κλάσης list.
*/
#include "template_list.hpp"

template <class T>
list <T>::list() {head=nullptr;}

template <class T> list <T>::list(T d) {
    this->head=new node<T>;
    this->head->data=d;
    this->head->next=nullptr;
}

template <class T>list<T>::~list() {
    while(this->head!=nullptr)
    {
        node <T> *erasenode=this->head;
        this->head=this->head->next;
        delete erasenode;
    }
}

template <class T>void list<T>::push_back(T d)
{
    if(this->head==nullptr)
    {
        this->head=new node<T>;
        this->head->data=d;
        this->head->next=nullptr;
        return;
    }
    node <T> *curr=this->head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    node <T> *newnode=new node<T>;
    newnode->data=d;
    newnode->next=nullptr;
    curr->next=newnode;
}

template <class T>void list<T>::push_front(T d)
{
    if(this->head==nullptr)
    {
        this->head=new node <T>;
        this->head->data=d;
        this->head->next=nullptr;
        return;
    }
   node <T> *newnode=new node <T>;
   newnode->data=d;
   newnode->next=nullptr;
   newnode->next=this->head;
   this->head=newnode;
}

template <class T>void list<T>::erase_front()
{
    node <T> *deletenode=this->head;
    this->head=this->head->next;
    delete deletenode;
}

template <class T>void list<T>::erase(int position)
{
    node <T> *curr=this->head;
    node <T> *deletenode;
    for(int i=1;i<position-1;i++)
    {
        curr=curr->next;
    }
    deletenode=curr->next;
    curr->next=curr->next->next;
    delete deletenode;
}

template <class T>void list<T>::insert(int position,T d)
{
   node <T> *curr=this->head;
   node <T> *newnode=new node<T>{d,nullptr};
   for(int i=1;i<position-1;i++)
   {
       curr=curr->next;
   }
   newnode->next=curr->next;
   curr->next=newnode;
}

template <class T>bool list<T>::is_Empty()
{
    if(this->head==nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template <class T>T list<T>::front()
{
    return this->head->data;
}

template <class T>T list<T>::back()
{
    node <T> *curr=this->head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    return curr->data;
}

template <class T>void list<T>::pop_back()
{
    node <T> *current=this->head;
    node <T> *prev;
    while(current->next!=nullptr)
    {
        prev=current;
        current=current->next;
    }
    prev->next=nullptr;
    delete current;
}

template <class T>int list<T>::length()
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

template <class T>void list<T>::print_list()
{
    node <T> *curr=this->head;
    std::cout<<"List:";
    while(curr!=nullptr)
    {
        if(curr->next!=nullptr)
       std::cout<<curr->data<<"->";
       else
       {
           std::cout<<curr->data;
       }
       curr=curr->next;
    }
    std::cout<<std::endl;
}

template <class T>void list<T>::reverse()
{
    node<T> *curr=this->head;
    const int size=this->length();
    T data[size];
    int j=size-1;
    while(curr!=nullptr)
    {
       data[j]=curr->data;
       curr=curr->next;
       j--;
    }
    j=0;
    curr=this->head;
    while(curr!=nullptr)
    {
        curr->data=data[j];
        curr=curr->next;
        j++;
    }
}

template <class T>void list<T>::bubblesort()
{
    int size=length()-1;
    node<T> *curr=this->head;
    while(curr!=nullptr)
    {
        node <T> *temp=this->head;
        for(int i=0;i<size;i++)
        {
            if(temp->data<temp->next->data)
            {
                T d=temp->data;
                temp->data=temp->next->data;
                temp->next->data=d;
            }
            temp=temp->next;
        }
        curr=curr->next;
    }
}

template <class T>void list<T>::selection_sort()
{
    node <T> *curr=this->head;
    node <T> *temp;
    int size=this->length(curr);
    int j;
    int i=1;
    while(curr!=nullptr)
    {
        T min=curr->data;
        temp=curr->next;
        int pos=i;
        for(int j=i+1;j<size;j++)
        {
            if(temp->data<min)
            {
                min=temp->data;
                pos=j;
            }
            temp=temp->next;
        }
        node <T> *search=this->head;
        for(int k=1;k<=pos;k++)
        {
            search=search->next;
        }
        T temporary=curr->data;
        curr->data=search->data;
        search->data=temporary;
        i++;
        curr=curr->next;
    }
}