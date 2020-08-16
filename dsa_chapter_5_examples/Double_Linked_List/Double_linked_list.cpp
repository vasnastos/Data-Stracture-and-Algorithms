#include <iostream>

struct node 
{
    int data;
    node *next;
    node *previous;
};

class double_link_list
{
    node *head;
    node *tail;
    public:
      double_link_list()
      {
          head=nullptr;
          tail=nullptr;
      }
      
      double_link_list(int d)
      {
          head=new node{d,nullptr,nullptr};
          tail=head;
      }

      ~double_link_list()
      {
          while(this->head!=nullptr)
          {
              node *delnode=this->head;
              this->head=this->head->next;
              delete delnode;
          }
          delete this->tail;
          std::cerr<<"Elements erased!!!!!!!!!!!"<<std::endl;
      }

      void push_front(int d)
      {
          if(head==nullptr)
          {
              head=new node{d,nullptr,nullptr};
              tail=head;
              return;
          }
          node *newnode=new node{d,nullptr,nullptr};
          newnode->next=head;
          this->head->previous=newnode;
          this->head=newnode;
      }

      int length()
      {
          int len=0;
          node *curr=this->head;
          while(curr!=nullptr)
          {
              len++;
              curr=curr->next;
          }
          return len;
      }

      void push_back(int d)
      {
          node *newnode=new node{d,nullptr,nullptr};
          newnode->previous=tail;
          this->tail->next=newnode;
          this->tail=newnode;
      }

      void erase_front()
      {
          node *delnode=this->head;
          this->head=this->head->next;
          this->head->previous=nullptr;
          delete delnode;
      }

      void popback()
      {
          node *delnode=this->tail;
          this->tail=this->tail->previous;
          this->tail->next=nullptr;
          delete delnode;
      }

      void insert(int pos,int d)
      {
          if(pos<=0 || pos>=length())
          {
              std::cerr<<"Invalid position"<<std::endl;
              return;
          }
          node *curr=this->head;
          for(int i=1;i<pos-1;i++)
          {
              curr=curr->next;
          }
          node *insertion=curr->next;
          node *newnode=new node{d,nullptr,nullptr};
          curr->next=newnode;
          newnode->previous=curr;
          newnode->next=insertion;
          insertion->previous=newnode;
      }

      void erase(int pos)
      {
          if(pos<0 || pos>=length())
          {
              std::cerr<<"Invalid position"<<std::endl;
              return;
          }
          node *curr=this->tail;
          for(int i=length()-1;i>pos;i--)
          {
              curr=curr->previous;
          }
          node *delnode=curr->previous;
          node *before=curr->previous->previous;
          curr->previous=before;
          before->next=curr;
          delete delnode;
      }

     int front() {return this->head->data;}

     int back() {return this->tail->data;}

     bool is_empty() {return this->head==nullptr;}

      void printlist()
      {
          node *curr=this->head;
          std::cout<<"List:";
          while(curr!=nullptr)
          {
              std::cout<<curr->data<<" ";
              curr=curr->next;
          }
          std::cout<<std::endl;
      }
};

int main()
{
    double_link_list dll(3);
    
    std::cout<<"Empty list:";
    
    if(dll.is_empty())
    {
        std::cout<<"True"<<std::endl;
    }

    else
    {
        std::cout<<"False"<<std::endl;
    }
    
    for(int i=4;i<9;i++)
    {
        dll.push_back(i);
    }
    std::cout<<"After pushBack"<<std::endl;
    dll.printlist();
    dll.erase_front();
    std::cout<<"After Erase_Front"<<std::endl;
    dll.printlist();
    dll.push_front(12);
    std::cout<<"After push_Front"<<std::endl;
    dll.printlist();
    dll.erase(4);
    std::cout<<"After erase position 4"<<std::endl;
    dll.printlist();
    dll.insert(2,43);
    std::cout<<"After insertion of number 43 in position 2"<<std::endl;
    dll.printlist();
    dll.popback();
    std::cout<<"After popback"<<std::endl;
    dll.printlist();
    std::cout<<"Front-Back details"<<std::endl;
    std::cout<<"Front:"<<dll.front()<<std::endl;
    std::cout<<"Back:"<<dll.back()<<std::endl;
    return 0;
}