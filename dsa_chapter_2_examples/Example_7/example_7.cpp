/*
ΑΣΚΗΣΗ:
   Να κατασκευαστεί πρόγραμμα που θα προσομοιώνει τις εξής λειτουργείες τηλεφωνικου καταλογού:
   •Αναζήτηση(Έυρεση αριθμού με βάση το όνομα και την περιοχή).
   •Εμφάνιση στοιχείων με βάση την περιοχή.
   •Διαγραφή ενός αριθμού από την δομή. 
   •Προσθήκη αριθμού στο αρχείο.
   •Να κατασκευαστεί ένα αρχείο που θα προσομοιώνει μία βάση δεδομένων.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <tuple>
//tuple-->εγγραφή χρησιμοποιήται για να προσομοιώνει 
//δεδομένα από αρχεία οι βάσεις δεδομένων.

void export_data(std::vector <std::tuple<std::string,std::string,std::string>> &records)
{
    std::ifstream is;
    std::string line,word;
    std::vector <std::string> data; 
    is.open("database.txt",std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        data.clear();
        while(std::getline(ss,word,','))
        {
            data.push_back(word);
        }
        if(data.size()!=3) continue;
        std::tuple<std::string,std::string,std::string> newrecord;
        newrecord=std::make_tuple(data[0],data[1],data[2]);
        records.push_back(newrecord); 
    } 
    is.close();
}

void search(std::vector <std::tuple<std::string,std::string,std::string>> &records,std::string n,std::string ar)
{
    for(auto &x:records)
    {
        if(std::get<0>(x)==n && std::get<1>(x)==ar)
        {
            std::cout<<"PhoneNumber for "<<name<<":"<<std::get<2>(x)<<std::endl;
            break;
        }
    }
}

void search(std::vector <std::tuple<std::string,std::string,std::string>> &records,std::string ar)
{
    std::cout<<"****** Information for Area:"<<ar<<" ******"<<std::endl;
    for(auto &x:records)
    {
       if(std::get<1>(x)==ar)
       {
           std::cout<<"Name:"<<std::get<0>(x)<<"\tPhone:"<<std::get<2>(x)<<std::endl;
       }
    }
    std::cout<<"*********************************************"<<std::endl;
}

void reload_table(std::vector <std::tuple<std::string,std::string,std::string>> &records)
{
    std::string filename="database.txt";
    std::ofstream out;
    out.open(filename,std::ios::out);
    for(auto &x:records)
    {
        out<<std::get<0>(x)<<","<<std::get<1>(x)<<","<<std::get<2>(x)<<std::endl;
    }
    out.close();
}

void delete_record(std::vector <std::tuple<std::string,std::string,std::string>> &records)
{
    std::string area,name;
    std::cout<<"Give name you want to delete:";
    std::cin>>name;
    std::cout<<"Give area you want to delete:";
    std::cin>>area;
    int pos=-1;
    int i=0;
    for(auto &x:records)
    {
        if(std::get<0>(x)==name && std::get<1>(x)==area)
        {
           pos=i;
           break;
        }
        i++;
    }
    records.erase(records.begin()+pos);
    reload_table();
}

void add_record(std::vector <std::tuple<std::string,std::string,std::string>> &records)
{
    std::string name,area,phone;
    std::cout<<"Give name:";
    std::cin>>name;
    std::cout<<"Give area:";
    std::cin>>area;
    std::cout<<"Give phone:";
    std::cin>>phone;
    bool found=false;
    for(auto &x:records)
    {
        if(std::get<0>(x)==name && std::get<1>(x)==area)
        {
            found=true;
        }
    }
    if(!found)
    {
        std::tuple<std::string,std::string,std::string> newrecord=std::make_tuple(name,area,phone);
        records.push_back(newrecord);
    }
    else
    {
        std::cout<<"Record already exists!!!!"<<std::endl;
    }
}

int main_menu()
{
    int ch;
    std::cout<<"1-Add Record"<<std::endl;
    std::cout<<"2-Delete Record"<<std::endl;
    std::cout<<"3-search Record"<<std::endl;
    std::cout<<"4-Search by area"<<std::endl;
    std::cout<<"Give choice:";
    std::cin>>ch;
    return ch;
}

int main()
{
    std::vector <std::tuple<std::string,std::string,std::string>> phonesdb;
    export_data(phonesdb); 
    std::string name,area;  
    int choice;
    while(true)
    {
       choice=main_menu();
       if(choice==1)
       {
           add_record(phonesdb);
       }
       else if(choice==2)
       {
           delete_record(phonesdb);
       }
       else if(choice==3)
       {
           std::cout<<"Give name:";
           std::cin>>name;
           std::cout<<"Give area:";
           std::cin>>area;
           search(phonesdb,name,area);
       }
       else if(choice==4)
       {
           std::cout<<"Give area:";
           std::cin>>area;
           search(phonesdb,area);
       }
       else
       {
           std::cerr<<"Invalid choice!!!"<<std::endl;
       } 
    }
}