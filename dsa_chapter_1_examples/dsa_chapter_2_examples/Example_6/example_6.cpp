/*
LAMBDAS IN STL
Η δυνατότητα lambdas επιτρέπει τη συγγραφή ανώνυμων συναρτήσεων 
στο σημείο που χρειάζονται, διευκολύνοντας με αυτό τον τρόπο τη συγγραφή προγραμμάτων.
Προσβασιμότητα
  • []: καμία πρόσβαση σε εξωτερικές της lambda συνάρτησης μεταβλητές.
  • [&]: πρόσβαση σε όλες τις εξωτερικές μεταβλητές με αναφορά.
  • [=]: πρόσβαση σε όλες τις εξωτερικές μεταβλητές με τιμή.
  • [a, &b]: πρόσβαση στην a με τιμή και πρόσβαση στη b με αναφορά.
  ΑΣΚΗΣΗ:
    Να κατασκευαστεί πρόγραμμα το οποίο θα διαβάζει δεδομένα από ένα αρχείο employees.txt
    και να πραγματοποιεί τα ακόλουθα:
       •Να βρίσκει μέσω lambda συναρτησης πόσοι υπάλληλοι έχουν μισθό μεγαλύτερο του μέσου όρου.
       •Να πραγματοποιηθεί ταξινόμιση σε αύξουσα σειρά και εμφάνιση των υπαλλήλων. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>

struct employee
{
  std::string name;
  std::string dep;
  double salary;
};

double summary(double s,const employee &e)
{
   return s+e.salary;
}

void read_data(std::vector <employee> &v)
{
   std::string line;
   std::ifstream is;
   std::vector <std::string> data;
   is.open("data.txt",std::ios::in);
   while(std::getline(is,line))
   {
     if(line.at(0)=='#') continue;
     if(line.size()==0) continue;
     std::stringstream ss(line);
     data.clear();
     while(std::getline(ss,word,'-'))
     {
        data.push_back(word);
     }
     if(data.size()!=3) continue;
     employee emp;
     emp.name=data[0];
     emp.dep=data[1];
     emp.salary=std::stod(data[2]);
     v.push_back(emp);
   }
   is.close();
}

int main()
{
   std::vector <employee> emps;
   read_data(emps);
   double avg=std::accumulate(emps.begin(),emps.end(),0.0,summary)/emps.size();
   int cnt=std::count_if(emps.begin(),emps.end(),[avg](employee &x) {return x.salary>avg;});
   std::cout<<"Salaries over average:"<<cnt<<std::endl;
   std::cout<<"****** EMPLOYEES LIST ******"<<std::endl;
   sort(emps.begin(),emps.end(),[](const employee &e1,const employee &e2) {return e1.salary>e2.salary;})
   for(std::vector <employee>::iterator itr=emp.begin();itr!=emp.end();itr++)
   {
     std::cout<<"Name:"<<emps[i].name<<"\tDEPARTMENT:"<<emps[i].dep<<"\tSALARY:"<<emps[i].salary<<std::endl;
   }
   std::cout<<"*****************************"<<std::endl;
}