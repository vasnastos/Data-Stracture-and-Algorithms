/* 
 Έστω αρχείο που περιέχει στοιχεία τράπεζας(κωδικούς-τριψηφιους,χρήματα):Να κατασκευαστεί πρόγραμμα το οποίο θα διαβάζει τα 
 στοιχεία και θα εκτελεί την παρακάτω λειτουργικότητα:
   •Εύρεση υπολοίπου με βάση τον κωδικό.
   •Αλλαγή κωδικού και ενημέρωση του αρχείου.
   •κατάθεση σε έναν λογαριασμό(ενημέρωση αρχείου).
   •Διαγραφή λογαριασμόύ(ενημέρωση του αρχείου).
   •Ανάληψη από έναν λογαριασμό(ενημέρωση αρχείου).
*/
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string fn="bank.txt";

void read_data(map <string,double> &bank)
{
    ifstream is;
    string line,word;
    vector <string> data;
    string data1;
    double data2;
    is.open(fn);
    while(getline(is,line))
    {
        data.clear();
        stringstream bi(line);
        while(getline(bi,word,'-'))
        {
            data.push_back(word);
        }
        data1=data[0];
        data2=stod(data[1]);
        bank.insert(make_pair(data1,data2));
    }
    is.close();
}

void find_balance(map <string,double> &mp)
{
    string id;
    cout<<"Give code to search in bank System:";
    cin>>id;
    if(mp.find(id)!=mp.end())
    {
        cout<<"Your Balance is:"<<mp[id]<<endl;
    }
    else
    {
        cout<<"code did not found!!!"<<endl;
    }
    
}

void change_password(map <string,double> &mp)
{
   string pas;
   cout<<"Give your old password:";
   cin>>pas;
   string newpass;
   if(mp.find(pas)!=mp.end())
   {

       double temp=mp[pas];
       mp.erase(mp.find(pas));
       cout<<"Give your new password:";
       cin>>newpass;
       mp.insert(make_pair(newpass,temp));
   }
}