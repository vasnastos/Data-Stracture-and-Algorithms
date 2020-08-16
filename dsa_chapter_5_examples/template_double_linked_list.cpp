#include "template_double_linked_list.hpp"

template <class T>double_linked_list <T>::double_linked_list():head(nullptr),tail(nullptr) {}

template <class T>double_linked_list <T>::double_linked_list(T d)
{      
  head=new node<T>{d,nullptr,nullptr};
  tail=head;
}

template <class T>void double_linked_list<T>::push_front(T d)
{
  node <T> *newnode=new node<T>{d,nullptr,nullptr};
  newnode->next=this->head;
  this->head->previous=newnode;
  this->head=newnode;
}

template <class T>double_linked_list <T>::~double_linked_list()
{
   while(this->head!=nullptr)
    {
        node <T> *delnode=this->head;
        this->head=this->head->next;
        delete delnode;
    }
}

template <class T>void double_linked_list<T>::push_back(T d)
{
    node <T> *newnode=new node<T>;
    newnode->data=d;
    newnode->next=nullptr;
    this->tail->next=newnode;
    newnode->previous=this->tail;
    this->tail=newnode;
}

template <class T>int double_linked_list<T>::length()
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

template <class T>void double_linked_list<T>::insert(int pos,T d)
{
    node <T> *curr;
          int check=length()/2;
          if(pos<=check)
          {
              curr=this->head;
              for(int i=1;i<pos;i++)
              {
                 curr=curr->next;
              }
              node <T> *nextnode=curr->next;
              node <T> *newnode=new node<T>{d,nullptr,nullptr};
              newnode->previous=curr;
              curr->next=newnode;
              newnode->next=nextnode;
              nextnode->previous=newnode;
          }
          else
          {
              curr=this->tail;
              int size=this->length()-1;
              for(int i=size;i>pos;i--)
              {
                 curr=curr->previous;
              }
              node <T> *prevnode=curr->previous;
              node <T> *newnode=new node<T>{d,nullptr,nullptr};
              newnode->previous=prevnode;
              prevnode->next=newnode;
              newnode->next=curr;
              curr->previous=newnode;
          } 
}

template <class T>void double_linked_list<T>::erase(int position)
{
              node <T> *curr;
          int check=this->length()-1;
          if(position<=check)
          {
              curr=this->head;
              for(int i=1;i<position;i++)
              {
                  curr=curr->next;
              }
              node <T> *delnode=curr->next;
              curr->next=curr->next->next;
              curr->next->previous=curr;
              delete delnode;
          }
          else
          {
              curr=this->tail;
              int size=this->length()-1;
              for(int i=size;i>position;i--)
              {
                  curr=curr->previous;
              }
              node <T> *delnode=curr->previous;
              curr->previous=curr->previous->previous;
              curr->previous->next=curr;
              delete delnode;
          }
}

template <class T>T double_linked_list<T>::front() {return this->head->data;}

template <class T>T double_linked_list<T>::back() {return this->tail->data;}

template <class T>void double_linked_list<T>::printlist()
{
    node <T> *curr=this->head;
          std::cout<<"List:";
          int i=1;
          int size=this->length();
          while(curr!=nullptr)
          {
              if(i<size-1)
              {
                  std::cout<<curr->data<<"->";
              }
              else
              {
                  std::cout<<curr->data;
              }
              i++;
          }
          std::cout<<std::endl;
          std::cout<<std::endl;
}

template <class T>void double_linked_list<T>::erase_front()
{
    node <T> *delnode=this->head;
    this->head=this->head->next;
    this->head->previous=nullptr;
    delete delnode;
}

template <class T>void double_linked_list<T>::popback()
{
    node <T> *dnode=this->tail;
    this->tail=this->tail->previous;
    this->tail->next=nullptr;
    delete dnode;
}

template <class T>void double_linked_list<T>::operator<<(T d)
{
    node <T> *newnode=new node<T>{d,nullptr,nullptr};
    this->tail->next=newnode;
    newnode->previous=this->tail;
    this->tail=newnode;
}