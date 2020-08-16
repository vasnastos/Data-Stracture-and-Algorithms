/*
Στο παρακάτω κομμάτι κώδικα Υλοποιούνται οι παρακάτω συναρτήσεις:
 •Διαγραφη πρώτου κόμβου της λίστας.
 •τιμή πρώτου κόμβου της λίστας.
 •τιμή τελευταίου κόμβου. 
 •Αφαίρεση τελευταίου κόμβου της λίστας.
 •διαγραφή ενός κόμβου με βάση την θέση του.
 •Ταξινόμιση με επιλογή.
*/

#include <iostream>
#include "list1.cpp"
//used ready function from list1.cpp source file

void erase_front(node *&curr)
{
  node *temp=curr;
  curr=curr->next;
  delete temp;
}

//Δεδομένα πρώτου κόμβο
int front(node *curr)
{
   return curr->data;
}

//Δεδομένα τελευταίου κόμβου
int back(node *curr)
{
   while(curr->next!=nullptr)
   {
       curr=curr->next;
   }
   return curr->data;
}

//Διαγραφή τελευταίου κόμβου
void pop_back(node *curr)
{
    node *t;
    while(curr->next!=nullptr)
    {
        t=curr;
        curr=curr->next;
    }
    t->next=nullptr;
    delete curr;
}

//Διαγραφή με βάση την θέση
void erase(node *curr,int pos)
{
    for(int i=1;i<pos-1;i++)
    {
        curr=curr->next;
    }
    node *t=curr->next;
    curr->next=curr->next->next;
    delete t;
}

//Ταξινόμιση με επιλογή
void selection_sort(node *curr)
{
    int size=length(curr);
    node *temp;
    node *search=curr;
    for(int i=0;i<size;i++)
    {
        int pos=i;
       int min=curr->data;
       temp=curr->next;
       for(int j=i+1;j<size;j++)
       {
           if(temp->data<min)
           {
               min=temp->data;
               pos=j;
           }
           temp=temp->next;
       }
       node *f=search;
       for(int k=1;k<=pos;k++)
       {
           f=f->next;
       }
       int temporary=curr->data;
       curr->data=f->data;
       f->data=temporary;
       curr=curr->next;
    }
}

//Κύριως κώδικας εκτέλεσης παραδειγμάτων για αρχεία list1.cpp--list2.cpp
int main()
{
    std::vector <int> data;
    read_data(data);
    //push the elements to the list.
    node *head=new node{data.at(0),nullptr};
    for(int i=1;i<data.size();i++)
    {
        push_back(head,data.at(i));
        print_list(head);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    //erase front
    std::cout<<"Erase front element of the list"<<std::endl;
    erase_front(head);
    print_list(head);
    //erase from position
    int pos;
    std::cout<<"Give position you want to erase:";
    std::cin>>pos;
    if(pos>=length(head))
    {
        std::cerr<<"Invalid position you can't erase from this position"<<std::endl;
    }
    else
    {
        std::cout<<"Erase position "<<pos<<std::endl;
        erase(head,pos);
    }
    print_list(head);
     std::cout<<"Popback an element"<<std::endl;
     pop_back(head);
     print_list(head);
    //Sort by shallow copy with selection sort
    std::cout<<"Sort list using selction sort algorithm!!!"<<std::endl;
    selection_sort(head);
    print_list(head);
}