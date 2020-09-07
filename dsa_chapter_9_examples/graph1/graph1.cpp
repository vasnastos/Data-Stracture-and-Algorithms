/*
Ανάγνωση δεδομένων από αρχείο και εύρεση συνδεδεμένων κορυφών για κάθε κορυφή του γραφήματος.
Η κορυφές αναπαρίστανται με κεφαλαία γράμματα της αγγλικής αλφαβήτου.
Το γράφημα είναι μη κατευθυνόμενο.
Θα χρησιμοποιηθεί πίνακας γειτνίασης.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct vertex
{
    std::string vertexname;
    int weight;
};

std::string *vertices;

int countdata()
{
    std::ifstream is;
    std::string line;
    is.open("graph.txt",std::ios::in);
    int counter=0;
    while(std::getline(is,line))
    {
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
       counter++;
    }
    is.close();
    return counter;
}

void readdata(int **data)
{
   std::ifstream is;
   std::string line,word;
   std::vector <std::string> lns;
   is.open("graph.txt");
   int i=0;
   while(std::getline(is,line))
   {
       int j=0;
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
       lns.clear();
       std::stringstream ss(line);
       while(std::getline(ss,word,','))
       {
          lns.push_back(word);
       }
       for(auto &x:lns)
       {
           data[i][j]=std::stoi(x);
           j++;
       }
       i++;
   }
   is.close();
}

std::vector <vertex> get_vertex_connected_vertices(int **adj,std::string ver,int size)
{
    std::vector <vertex> conn;
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(vertices[i]==ver)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        std::cerr<<"Vertex does not exist"<<std::endl;
        return conn;
    }
    for(int j=0;j<size;j++)
    {
        if(adj[pos][j]!=0)
        {
           vertex v;
           v.vertexname=vertices[j];
           v.weight=adj[pos][j];
           conn.push_back(v);
        }
    }
    return conn;
}

void fillvertices(int size)
{
    vertices=new std::string[size];
    for(int i=0;i<size;i++)
    {
        vertices[i]='A'+i;
    }
}

void show_connected_vertices(int **adj,int size)
{
    std::cout<<"************************** Graph connected vertices *************************************************"<<std::endl;
    for(int i=0;i<size;i++)
    {
        std::cout<<"Vertex "<<vertices[i]<<":";
        std::vector <vertex> cvers=get_vertex_connected_vertices(adj,vertices[i],size);
        for(auto &y:cvers)
        {
            std::cout<<y.vertexname<<"-"<<y.weight<<"\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<"*****************************************************************************************************"<<std::endl;
}

void delete_mem(int **a,int size)
{
    for(int i=0;i<size;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] vertices;
}

int main()
{
    int cnt=countdata();
    fillvertices(cnt);
    int **adj_matrix=new int*[cnt];
    for(int i=0;i<cnt;i++)
    {
        adj_matrix[i]=new int[cnt];
    }
    readdata(adj_matrix);
    show_connected_vertices(adj_matrix,cnt);
    delete_mem(adj_matrix,cnt);
}