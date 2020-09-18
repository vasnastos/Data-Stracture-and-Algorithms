#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct node
{
    std::string vertex;
    node *next;
};

class adjlist
{
    std::string vert;
    node *head;
    public:
      adjlist(std::string n):vert(n),head(nullptr) {}
      void delete_list()
      {
          while(this->head!=nullptr)
          {
              node *temp=this->head;
              this->head=this->head->next;
              delete temp;
          }
      }
      void push_back(std::string v)
      {
          if(this->head==nullptr)
          {
              this->head=new node{v,nullptr};
              return;
          }
          node *current=this->head;
          while(current->next!=nullptr)
          {
              current=current->next;
          }
          node *newvertexnode=new node{v,nullptr};
          current->next=newvertexnode;
      }
      void print()
      {
          node *curr=this->head;
          std::cout<<this->vert<<"->";
          while(curr!=nullptr)
          {
              std::cout<<curr->vertex<<" ";
              curr=curr->next;
          }
          std::cout<<std::endl;
      }
};

void read_data(std::vector <adjlist> &vertices)
{
   std::ifstream is;
   std::string line,word;
   std::vector <std::string> data;
   is.open("graph2.txt",std::ios::in);
   int i=0;
   while(std::getline(is,line))
   {
       data.clear();
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
           data.push_back(word);
        }  
        char k='A'+i;
        std::string vrt="";
        vrt+=k;
        adjlist vertx(vrt);
        for(int j=0;j<data.size();j++)
        {
            if(std::stoi(data.at(j))!=0)
            {
                char newvertex='A'+j;
                std::string vtr="";
                vtr+=newvertex;
                vertx.push_back(vtr);
            }
        }
        vertices.push_back(vertx);
        i++;
   }
   is.close();
}

void showgraph(std::vector <adjlist> &vertices)
{
    for(auto itr=vertices.begin();itr!=vertices.end();itr++)
    {
        itr->print();
    }
}

void free_mem(std::vector <adjlist> &ver)
{
    for(auto &x:ver)
    {
        x.delete_list();
    }
}

int main()
{
    std::vector <adjlist> vertices;
    read_data(vertices);
    showgraph(vertices);
    free_mem(vertices);
    return 0;
}
