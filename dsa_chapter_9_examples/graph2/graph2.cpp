/*
Ανάγνωση δεδομένων από αρχείο και εύρεση συνδεδεμένων κορυφών για κάθε κορυφή του γραφήματος.
Η κορυφές αναπαρίστανται με κεφαλαία γράμματα της αγγλικής αλφαβήτου.
Το γράφημα είναι μη κατευθυνόμενο.
Θα χρησιμοποιηθεί λίστα γειτνίασης.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct vertex
{
    std::string vertexname;
    int weight;
    vertex *next;
};
class adjest
{
    std::string checkvertex;
    vertex *head;
    public:
     adjest(std::string vr):checkvertex(vr),head(nullptr) {}
     ~adjest()
     {
         while(head!=nullptr)
         {
             vertex *del=head;
             head=head->next;
             delete del;
         }
     }
     void pushback(std::string name,int wh)
     {
         if(head==nullptr)
         {
             head=new vertex{name,wh,nullptr};
             return;
         }
         vertex *curr=head;
         vertex *v=new vertex{name,wh,nullptr};
         while(curr->next!=nullptr)
         {
             curr=curr->next;
         }
         curr->next=v;
     }
     void print()
     {
         std::cout<<"Vertex:"<<checkvertex<<":";
         vertex *curr=head;
         while(curr!=nullptr)
         {
             std::cout<<curr->vertexname<<"-"<<curr->weight<<"\t";
             curr=curr->next;
         }
         std::cout<<std::endl;
     }
};

std::vector <adjest> connvers;
std::string *vertices;

void fillvertices()
{
   std::ifstream is;
   std::string line;
   int counter=0;
   is.open("graph2.txt",std::ios::in);
   while(std::getline(is,line))
   {
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
       counter++;
   }
   is.close();
   vertices=new std::string[counter];
   for(int i=0;i<counter;i++)
   {
       vertices[i]='A'+i;
       std::cout<<"Vertex:"<<vertices[i]<<std::endl;
   }
}

void readdata()
{
    std::string line,word;
    std::vector <std::string> data;
    std::ifstream is;
    is.open("graph2.txt",std::ios::in);
    int i=-1;
    while(std::getline(is,line))
    {
        i++;
        adjest newvertex(vertices[i]);
        newvertex.print();
        std::stringstream ss(line);
         data.clear();
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        for(int j=0;j<data.size();j++)
        {
            if(std::stoi(data.at(j))!=0)
            {
               newvertex.pushback(vertices[j],std::stoi(data.at(j))); 
            }
        }
        newvertex.print();
        connvers.push_back(newvertex);  
    }
    is.close();
}

void show_connected_vertices()
{
    std::cout<<"*************************** Graph Vertices ***********************************"<<std::endl;
    for(auto &x:connvers)
    {
        x.print();
    }
    std::cout<<"******************************************************************************"<<std::endl;
}


int main()
{
    fillvertices();
    readdata();
    show_connected_vertices();
    return 0;
}