/*
Εύρεση συνδεδεμένων κορυφών κατευθυνόμενου γραφήματος
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

int **adj_matrix;
std::string *vertices;
int size;

void read_data()
{
    std::ifstream is;
    std::string line,word;
    is.open("dag.txt");
    int counter=0;
    while(std::getline(is,line))
    {
        counter++;
    }
    size=counter;
    is.close();
    adj_matrix=new int*[counter];
    vertices=new std::string[counter];
    for(int i=0;i<counter;i++)
    {
        vertices[i]='A'+i;
        adj_matrix[i]=new int[counter];
    }
    is.open("dag.txt");
    int i=0;
    std::vector <std::string> data;
    while(std::getline(is,line))
    {
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        for(int j=0;j<data.size();j++)
        adj_matrix[i][j]=std::stoi(data.at(j));
        i++;
    }
    is.close();
}

void delete_data()
{
    delete[] vertices;
    for(int i=0;i<size;i++)
    {
        delete[] adj_matrix[i];
    }
    delete[] adj_matrix;
}

std::vector <vertex> get_conn_vertices(std::string k)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(vertices[i]==k)
        {
            pos=i;
        }
    }
    std::vector <vertex> conn;
    for(int j=0;j<size;j++)
    {
        if(adj_matrix[pos][j]!=0)
        {
            vertex v1;
            v1.vertexname=vertices[j];
            v1.weight=adj_matrix[pos][j];
            conn.push_back(v1);
        }
    }  
    return conn;
}

void show_connected()
{
    for(int i=0;i<size;i++)
    {
        std::cout<<"Vertex "<<vertices[i]<<": ";
        std::vector <vertex> connected=get_conn_vertices(vertices[i]);
        for(auto &x:connected)
        {
            std::cout<<x.vertexname<<"-"<<x.weight<<"\t";
        }
        std::cout<<std::endl;
    }
}

int main()
{
  read_data();
  show_connected();
  delete_data();
  return 0;   
}