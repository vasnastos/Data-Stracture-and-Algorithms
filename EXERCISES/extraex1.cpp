/*
Να γράψετε πρόγραμμα που να γεμίζει έναν πίνακα 100 θέσεων με τυχαίες ακέραιες τιμές στο διάστημα [0,1000].
 Κατασκευάστε μια συνάρτηση που να δέχεται 
τον πίνακα ως παράμετρο και να επιστρέφει τη μέση τιμή, τη μικρότερη τιμή και τη μεγαλύτερη τιμή του πίνακα.
Εμφανίστε στη main τα αποτελέσματα.
*/
#include <iostream>
#include <random>
#include <sstream>
#define SIZE 100

int seed()
{
    std::string tm=__TIME__;
    std::string word;
    std::stringstream ss(tm);
    while(std::getline(ss,word,':'))
    {

    }
    return std::stoi(word);
}

void function(int *a,double &avg,int &max,int &min)
{
   max=a[0];
   min=*a;
   int sum=a[0];
   for(int i=1;i<SIZE;i++)
   {
       sum+=*(a+i);
       if(*(a+i)>max)
       {
           max=*(a+i);
       }
       if(*(a+i)<min)
       {
           min=a[i];
       }
   }
   avg=(double)sum/SIZE;
}

int main()
{
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> dist(0,1000);
    int table[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        table[i]=dist(mt);
    }
    double average;
    int max,min;
    function(table,average,max,min);
    std::cout<<"Average:"<<average<<std::endl;
    std::cout<<"Max:"<<max<<std::endl;
    std::cout<<"Min:"<<min<<std::endl;
}