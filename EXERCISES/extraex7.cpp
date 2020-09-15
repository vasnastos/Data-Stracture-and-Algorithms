#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int data_size()
{
   std::ifstream is;
   std::string line;
   int counter=0;
   is.open("contacts.txt");
   while(std::getline(is,line))
   {
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
       counter++;
   }
   is.close();
   return counter;
}

void read_data(std::string *names,std::string phones[])
{
   std::ifstream fin;
   std::string line,word;
   std::vector <std::string> data;
   fin.open("contacts.txt",std::ios::in);
   int i=0;
   while(std::getline(fin,line))
   {
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        names[i]=data[0];
        phones[i]=data[1];
        i++;
   }
   fin.close();
}

struct contact
{
    std::string name;
    std::string phone;
    contact *next;
    void print()
    {
        std::cout<<name<<"--"<<phone<<std::endl;
    }
};

class list
{
    contact *head;
    public:
      list():head(nullptr) {}
      ~list()
      {
          while(this->head!=nullptr)
          {
              contact *delnode=this->head;
              this->head=this->head->next;
              delete delnode;
          }
      }
      void push_back(std::string n,std::string p)
      {
          if(this->head==nullptr)
          {
              this->head=new contact{n,p,nullptr};
              return;
          }
          contact *k=new contact{n,p,nullptr};
          contact *cur=head;
          while(cur->next!=nullptr)
          {
              cur=cur->next;
          }
          cur->next=k;
      }
      
      void push_front(std::string n,std::string p)
      {
          contact *c=new contact{n,p,nullptr};
          c->next=this->head;
          this->head=c;
      }

      void print()
      {
          contact *cur=this->head;
          std::cout<<"############## Contacts List ##################"<<std::endl;
          while(cur!=nullptr)
          {
             cur->print();
             cur=cur->next;
          }
          std::cout<<"################################################"<<std::endl;
      }
};

int main()
{
    int size=data_size();
    std::string *names,*phones;
    names=new std::string[size];
    phones=new std::string[size];
    read_data(names,phones);
    list contacts;
    for(int i=0;i<size;i++)
    {
        contacts.push_back(names[i],*(phones+i));
    }
    delete[] names;
    delete[] phones;
    contacts.print();
    std::cout<<std::endl;
    contacts.push_front("vasilis","6934567129");
    contacts.push_back("katerina","6978543671");
    contacts.print();
    return 0;
}