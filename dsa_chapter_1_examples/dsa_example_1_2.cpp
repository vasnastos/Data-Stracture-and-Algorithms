/*
Γράψτε το προηγούμενο πρόγραμμα ξανά χρησιμοποιώντας κλάση στη θέση της δομής. Επιπλέον ορίστε constructor
και getters/setters για τα μέλη δεδομένων του αντικειμένου υπάλληλος.
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class employee
{
     string name;
     double salary;
     int years;
   public:
     employee(string n="",double s=0.0,int yrs=0):name(n),salary(s),years(yrs) {}
     void set_name(string n) {this->name=n;}
     void set_salary(double s) {this->salary=s;}
     void set_years(int y) {this->years=y;}
     string get_name()const {return this->name;}
     double get_salary()const {return this->salary;}
     int get_years()const {return this->years;}
     friend ostream &operator<<(ostream &os,const employee &e)
     {
         os<<"Name:"<<e.name<<"\tSalary:"<<e.salary<<"\tYears:"<<e.years;
         return os;
     }
};

void function(employee *emps,int size)
{
    employee e[10];
   for(int i=0;i<size;i++)
   {
       cout<<emps[i]<<endl;
   }
   double mny=0.0;
   for(int i=0;i<size;i++)
   {
       if(emps[i].get_years()>=5)
       {
          mny+=emps[i].get_salary()*0.05;
          double newsalary=emps[i].get_salary()-(emps[i].get_salary()*0.05);
          emps[i].set_salary(newsalary);
       } 
       else 
       {
           mny+=emps[i].get_salary()*0.07;
          double newsalary=emps[i].get_salary()-(emps[i].get_salary()*0.07);
          emps[i].set_salary(newsalary);
       }
   }
   cout<<"Amount of money thats gone by hold"<<mny<<endl;
   cout<<"****** After holding:: ******"<<endl;
   for(int i=0;i<size;i++)
   {
       cout<<emps[i]<<endl;
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
    string value1;
    double value2;
    int value3;
    while(getline(is,line))
    {
        stringstream ss(line);
        //separated with space character.
        ss>>value1;
        //- separated
        //while(getline(ss,word,'-'))
        //c executable
        //char *token=strtok(line,"-"); while(token!=NULL) {//do something}
        ss>>value2;
        ss>>value3;
        employees[i].set_name(value1);
        employees[i].set_salary(value2);
        employees[i].set_years(value3);
        i++;
    }
    is.close();
    function(employees,counter);
    delete[] employees;
}