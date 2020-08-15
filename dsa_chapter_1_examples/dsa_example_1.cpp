/*
Γράψτε πρόγραμμα που να διαβάζει τα στοιχεία υπαλλήλων (όνομα, μισθό και έτη προϋπηρεσίας) από το αρχείο
data_ypallhlos_struct20.txt και να εμφανίζει τα στοιχεία του κάθε υπαλλήλου μέσω μιας συνάρτησης που θα δέχεται ως παράμετρο μια μεταβλητή τύπου δομής υπαλλήλου.
Στη συνέχεια να υπολογίζει και να εμφανίζει το ποσό που
θα συγκεντρωθεί αν για κάθε υπάλληλο με περισσότερα από 5 έτη προϋπηρεσίας παρακρατηθεί το 5% του μισθού του
ενώ για τους υπόλοιπους υπαλλήλους παρακρατηθεί το 7% του μισθού τους.
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct employee
{
   string name;
   double salary;
   int years;
};

void function(employee *emps,int size)
{
   for(int i=0;i<size;i++)
   {
       cout<<"Name:"<<emps[i].name<<"\tSalary:"<<emps[i].salary<<"\tYears:"<<emps[i].years;
   }
   double mny=0.0;
   for(int i=0;i<size;i++)
   {
       if(emps[i].years>=5)
       {
          mny+=emps[i].salary*0.05;
          emps[i].salary-=emps[i].salary*0.05;
       } 
       else 
       {
           mny+=emps[i].salary*0.07;
           emps[i].salary-=emps[i].salary*0.07;
       }
   }
   cout<<"Amount of money thats gone by hold"<<mny<<endl;
   cout<<"****** After holding:: ******"<<endl;
   for(int i=0;i<size;i++)
   {
       cout<<"Name:"<<emps[i].name<<"\tSalary:"<<emps[i].salary<<"\tYears:"<<emps[i].years;
   }
   cout<<"*****************************"<<endl;
}

int main()
{
    fstream is;
    string line;
    employee *employees;
    is.open("data_ypallhlos_struct20.txt",ios::in);
    int counter=0;
    while(getline(is,line))
    {
       counter++;
    }
    is.close();
    employees=new employee[counter];
    int i=0;
    is.open("data_ypallhlos_struct20.txt",ios::in);
    while(getline(is,line))
    {
        stringstream ss(line);
        //separated with space character.
        ss>>employees[i].name;
        //- separated
        //while(getline(ss,word,'-'))
        //c executable
        //char *token=strtok(line,"-"); while(token!=NULL) {//do something}
        ss>>employees[i].salary;
        ss>>employees[i].years;
        i++;
    }
    is.close();
    function(employees,counter);
    delete[] employees;
}