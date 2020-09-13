/*
 Υλοποιήστε τον αλγόριθμο του Kahn για τοπολογική ταξινόμηση κατευθυνόμενων ακυκλικών γραφημάτων (Directed Acyclic Graphs).
 Θεωρείστε ότι τα γραφήματα καταγράφονται σε πίνακες γειτνίασης. Για παράδειγμα o πίνακας γειτνίασης καταγράφεται 
 ως ο παρακάτω πίνακας.
      [0,1,0,0,0,0,0]
      [0,0,1,1,1,0,0]
      [0,0,0,0,1,0,0]
      [0,0,0,0,1,0,0]
      [0,0,0,0,0,1,0]
      [0,0,0,0,0,0,0]
      [0,0,0,1,0,0,0]
  Ειδικότερα, αναπτύξτε ένα πρόγραμμα που:

    Διαβάζει αρχείο στο οποίο είναι αποθηκευμένο ένα DAG.
    Εφαρμόζει τον αλγόριθμο τοπολογικής ταξινόμησης του Kahn και καταγράφει τα αποτελέσματα σε αρχείο.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

std::string filename="graph.txt";

int get_data_size()
{
   std::ifstream fin;
   fin.open(filename,std::ios::in);
   std::string line;
   int counter=0;
   while(std::getline(fin,line))
   {
       counter++;
   }
   fin.close();
   return counter;
}

void read_data(int **adj)
{
   std::ifstream fin;
   std::string line,word;
   std::vector <std::string> data;
   fin.open(filename);
   int i=0;
   while(std::getline(fin,line))
   {
       data.clear();
       std::stringstream ss(line);
       while(std::getline(ss,word,','))
       {
           data.push_back(word);
       }
       for(int j=0;j<data.size();j++)
       {
           adj[i][j]=std::stoi(data.at(j));
       }
       i++;
   }
   fin.close();
}

std::vector <char> get_connected_vertices(int **adj,int size,int vertex)
{
    std::vector <char> conn;
    for(int i=0;i<size;i++)
    {
        if(adj[vertex][i]!=0)
        {
            conn.push_back('A'+i);
        }
    }
    return conn;
}

void topological_search(int **adj,int s)
{
   std::queue <int> kahn;
   int *in_deggree=new int[s];
   //Εισερχόμενες κορυφές κάθε κόρυφης.
   for(int j=0;j<s;j++)
   {
       in_deggree[j]=0;
       for(int i=0;i<s;i++)
       {
           if(adj[i][j]!=0)
           {
               in_deggree[j]++;
           }
       }
   }
   std::vector <int> topological;
   for(int i=0;i<s;i++)
   {
       if(in_deggree[i]==0)
       {
           kahn.push(i);
       }
   }
   int countvisited=0;
   while(!kahn.empty())
   {
       int checkpos=kahn.front();
       kahn.pop();
       topological.push_back(checkpos);
       for(int j=0;j<s;j++)
       {
           if(adj[checkpos][j]!=0)
           {
               if(--in_deggree[j]==0)
               {
                   kahn.push(j);
               }
           }
       }
       countvisited++;
   }
   if(countvisited!=s)
   {
       std::cout<<"circle detected on the graph!!!!"<<std::endl;
       return;
   }
   std::cout<<"Kahn's Algorithm:";
   for(std::vector <int>::iterator itr=topological.begin();itr!=topological.end();itr++)
   {
       char k=(*itr)+'A';
       if(itr-topological.begin()<s-1)
       {
           std::cout<<k<<"->";
       }
       else
       {
           std::cout<<k<<std::endl;
       }   
   }
   int choice;
   std::cout<<"Save results to a file(0,yes|1,No)?:";
   std::cin>>choice;
   if(choice==0)
   {
       std::ofstream os;
       std::string fn;
       std::cout<<"Give filename:";
       std::cin>>fn;
       os.open(fn);
       os<<"File Created At:"<<__DATE__<<"  "<<__TIME__<<std::endl;
       os<<"Adjacency Matrix of the example"<<std::endl;
       os<<" |";
       for(int i=0;i<s;i++)
       {
           char k='A'+i;
           os<<k<<"|";
       }
       os<<std::endl;
       for(int i=0;i<s;i++)
       {
           char k='A'+i;
           os<<k<<"|";
           for(int j=0;j<s;j++)
           {
               os<<adj[i][j]<<"|";
           }
           os<<std::endl;
           os<<"--";
           for(int l=0;l<s;l++)
           os<<"--";
           os<<std::endl;
       }
       os<<std::endl;
       os<<"Graph Connected Vertices:::"<<std::endl;
       for(int i=0;i<s;i++)
       {
           char k='A'+i;
           os<<"Vertex "<<k<<":";
           std::vector <char> get_conn=get_connected_vertices(adj,s,i);
           if(get_conn.size()==0)
           {
               os<<"-"<<std::endl;
           }
           else
           {
               for(auto &x:get_conn)
               {
                   os<<x<<" ";
               }
               os<<std::endl;
           }
       }
       os<<std::endl;
       os<<"After Topological search Kahn's Algorithm::"<<std::endl;
       if(countvisited!=s)
       {
         os<<"circle detected on the graph!!!!"<<std::endl;
         os.close();
         return;
       }
       for(std::vector <int>::iterator itr=topological.begin();itr!=topological.end();itr++)
       {
           char k=(*itr)+'A';
         if(itr-topological.begin()<s-1)
         {
            os<<k<<"->";
         }
         else
         {
            os<<k<<std::endl;
         }   
       }
       os.close();
       delete[] in_deggree;
   }
}

int main()
{
    int **adj_matrix;
    int size=get_data_size();
    adj_matrix=new int*[size];
    for(int i=0;i<size;i++)
    {
        adj_matrix[i]=new int[size];
    }
    read_data(adj_matrix);
    topological_search(adj_matrix,size);
    for(int i=0;i<size;i++)
    {
        delete[] adj_matrix[i];
    }
    delete[] adj_matrix;
}