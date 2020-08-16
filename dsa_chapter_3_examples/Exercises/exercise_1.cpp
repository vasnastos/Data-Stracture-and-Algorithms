/*
 Να φτιαχτεί πρόγραμμα το οποίο θα διαβάζει στοιχεία για αυτοκίνητα(brand,model,year,price) τα οποία θα είναι 
 αποθηκευμένα σε αρχείο.
   Να υπολογιστούν τα παρακάτω:
     •Να βρεθούν τα αυτοκίνητα με τιμή μεγαλύτερη ενός αριθμού που θα εισάγει ο χρήστης.
     •Να βρεθούν τα μοντέλα που έχουν κατασκευαστεί από το έτος 2005-2009.
     •Να εμφανιστούν τα αυτοκίνητα μίας συγκεκριμένης χρονολογίας που θα εισάγει ο χρήστης.(Με την χρήση iterator).
     •Να εμφανιστούν όλα τα αυτοκίνητα(Range for).
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class car
{
    private:
      string brand;
      string model;
      int year;
      double price;
    public:
     car(string b,string m,int y,double p):brand(b),model(m),year(y),price(p) {}
     /*
     {
         price=p;
     }
     */
    string get_brand()const {return this->brand;}
    string get_model()const {return this->model;}
    int get_year()const {return this->year;}
    double get_price()const {return this->price;}
};

void read_data(vector <car> &c)
{
    ifstream ifs;
    string line,word;
    ifs.open("cars.txt");
    vector <string> data;
    while(getline(ifs,line))
    {
       stringstream ss(line);
       while(ss,word,',')
       {
           data.push_back(word);
       }
       if(data.size()!=4) continue;
       car newcar(data[0],data[1],stoi(data[2]),stod(data[3]));
       c.push_back(newcar);   
    }
    ifs.close();
}

void sbfp(vector <car> &c)
{
    double pr;
    cout<<"Give value to search:";
    cin>>pr;
    cout<<"**************** Cars with price over "<<pr<<" ********************"<<endl;
    //vector <car>::iterator itr=.....---->auto
    for(auto itr=c.begin();itr!=c.end();itr++)
    {
        if(itr->get_price()>pr)
        {
           cout<<"Brand:"<<itr->get_brand()<<"\tModel:"<<itr->get_model()<<"\tYear:"<<itr->get_year()<<endl;
        }
    }
    cout<<"*******************************************************************"<<endl;
}

void years2005_2009(vector <car> &c)
{
    for(auto itr=c.begin();itr!=c.end();itr++)
    {
        if(itr->get_year()>=2005 && itr->get_year()<=2009)
        {
           cout<<"Brand:"<<itr->get_brand()<<"\tModel:"<<itr->get_model()<<"\tPrice:"<<itr->get_price()<<endl;
        }
    }
}

void sbfy(vector <car> &c)
{
    int y;
    cout<<"Give value to search:";
    cin>>y;
    cout<<"**************** Cars constructed at "<<y<<" ********************"<<endl;
    //vector <car>::iterator itr=.....---->auto
    for(auto itr=c.begin();itr!=c.end();itr++)
    {
        if(itr->get_year()==y)
        {
           cout<<"Brand:"<<itr->get_brand()<<"\tModel:"<<itr->get_model()<<"\tPrice:"<<itr->get_price()<<endl;
        }
    }
    cout<<"*******************************************************************"<<endl;
}

void show(vector <car> &c)
{
   for(auto &val:c)
   {
      cout<<"Brand:"<<val.get_brand()<<"\tModel:"<<val.get_model()<<"\tYear:"<<val.get_year()<<"\tPrice:"<<val.get_price()<<endl;
   }
}

int main()
{
    vector <car> cars;
    read_data(cars);
    sbfp(cars);
    years2005_2009(cars);
    sbfy(cars);
    show(cars);
}