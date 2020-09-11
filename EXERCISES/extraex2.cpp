/*
Γράψτε πρόγραμμα που να διαβάζει το CSV αρχείο «Population Figures By Country» https://datahub.io/JohnSnowLabs/population-figures-by-country 
με στοιχεία πληθυσμού κρατών στο διάστημα 1960-2016 και να τα τοποθετεί σε κατάλληλους πίνακες.
Στη συνέχεια για κάθε χώρα να εμφανίζει το όνομά της και το έτος στο οποίο είχε τη μεγαλύτερη μεταβολή πληθυσμού.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

int count_data()
{
    std::ifstream fin;
    fin.open("source.csv",std::ios::in);
    std::string line;
    int counter=0;
    while(std::getline(fin,line))
    {
      counter++;
    }
    fin.close();
    return --counter;
}

int count_row()
{
  std::ifstream fin;
  std::string line,word;
  int counter=0;
  fin.open("source.csv",std::ios::in);
  std::getline(fin,line);
  if(std::getline(fin,line))
  {
      std::stringstream splitline(line);
      while(std::getline(splitline,word,','))
      {
          counter++;
      }
  }
  fin.close();
  counter-=2;
  return counter;
}

void read_data(std::string *country,std::string *code,unsigned int **abbr)
{
     std::ifstream fin;
     std::string line,word;
     fin.open("source.csv",std::ios::in);
     int i=0;
     int counter=0;
     while(std::getline(fin,line))
     {
        counter++;
        if(counter==1)
        {
            continue;
        }
        int k=0;
        int col=0;
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            if(k==0)
            country[i]=word;
            else if(k==1)
            {
                code[i]=word;
            }
            else
            {
                if(word=="")
                {
                    abbr[k-2][col]==0;
                }
                else
                {
                   abbr[k-2][col]=std::stoull(word);   
                }
                col++;
            }
            k++;
        }
        i++;
     }
     fin.close();
}

void calculate_change(std::string *country,std::string *code,unsigned int **abbr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        std::cout<<"Country:"<<country[i]<<" \tCountry Code:"<<code[i]<<"\t";
        long max;
        int pos;
        for(int j=1;j<col;j++)
        {
            if(j==1)
            {
                max=abbr[i][j]-abbr[i][j-1];
                if(max<0)
                {
                    max=-max;
                }
                pos=j;
            }
            else
            {
                long perc=abbr[i][j]-abbr[i][j-1];
                if(perc<0)
                {
                    perc=-perc;
                }
                if(perc>max)
                {
                    max=perc;
                    pos=j;
                }
            }
        }
        std::cout<<"Population change:"<<max<<"--Year:"<<1960+pos<<std::endl;
    }
}

int main(int argc,char **argv)
{
    std::string *country,*code;
    unsigned int **abbr;
    int total=count_data();
    int columns=count_row();
    std::cout<<total<<"---"<<columns<<std::endl;
    country=new std::string[total];
    code=new std::string[total];
    abbr=new unsigned int*[total];
    for(int i=0;i<total;i++)
    {
        abbr[i]=new unsigned int[columns];
    }
    read_data(country,code,abbr);
    calculate_change(country,code,abbr,total,columns);
    delete[] country;
    delete[] code;
    for(int i=0;i<total;i++)
    {
        delete[] abbr[i];
    }
    delete[] abbr;
}