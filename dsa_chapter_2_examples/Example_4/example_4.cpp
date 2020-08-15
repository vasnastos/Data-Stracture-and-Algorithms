/*
Οι iterators αποτελούν γενικεύσεις των δεικτών και επιτρέπουν την πλοήγηση στα στοιχεία ενός container με τέτοιο τρόπο
έτσι ώστε να μπορούν να χρησιμοποιηθούν οι ίδιοι αλγόριθμοι σε περισσότερα του ενός containers.

Παράδειγμα--Προσπέλαση ενός vector με 3 τρόπους
  1.Αυτόματη δεικτοδότηση
  2.Range for
  3.Iterators
Το vector θα περιέχει στοιχεία τύπου product
όπου η δομή περιέχει:
  Α)id-->Κωδικός Προιόντος
  Β)des-->περιγραφή προιόντος
  C)price-->Τιμή προιόντος. 
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <random>
#include <chrono>


using namespace std;
using namespace std::chrono;

struct product
{
    int id;
    string des;
    double price;
};

int main()
{
    vector <product> products;
    int seed=high_resolution_clock::now().time_since_epoch().count();
    mt19937 mten(seed);
    uniform_real_distribution <double> rand(1,9000);
    //vector που αποτελείται από προιόντα.(Μεταβλητές τύπου product).
    for(int i=0;i<10;i++)
    {
       product p;
       p.id=i+1;
       p.des="product_"+to_string(i+1);
       p.price=rand(mten);
    }
    cout<<"For loop"<<endl;
    for(int i=0;i<products.size();i++)
    {
        cout<<"ID:"<<products.at(i).id<<"\tNAME:"<<products.at(i).des<<"\tPRICE:"<<products.at(i).price<<endl;
    }
    cout<<"Range for loop"<<endl;
    for(auto &x:products)
    {
        cout<<"ID:"<<x.id<<"\tNAME:"<<x.des<<"\tPRICE:"<<x.price<<endl;
    }
    cout<<"show elements with iterator"<<endl;
    for(vector <product>::iterator itr=products.begin();itr!=products.end();itr++)
    {
       cout<<"ID:"<<itr->id<<"\tNAME:"<<itr->des<<"\tPRICE:"<<itr->price<<endl;
    }
}
