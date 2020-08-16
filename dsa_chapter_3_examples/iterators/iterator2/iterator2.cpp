/*
Να κατασκευαστεί πρόγραμμα που από ένα αρχείο numbers.csv θα διαβάζει τυχαίες γραμμές και στήλες και θα πραγματοποιεί
εύρεση του μέσου όρου κάθε γραμμής που διάβασε από το αρχείο και εμφάνιση του σε ένα αρχείο results.out
Η πρόσπέλαση του διανύσματος να πραγματοποιηθεί με iterator.Oι αριθμοί που αποθηκεύονται στο αρχείο είναι δεκαδικοί.
To πρόγραμμα να υλοποιηθεί με την χρήση συναρτήσεων.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void read_contents(vector <double> &nums)
{
    string line;
    ifstream is;
    //vector το οποίο θα αποθηκεύει τα δεδομένα από κάθε γραμμή.
    //Δεδομένα από το αρχείο ειναι αλφαριθμητικά άρα το vector θα δέχεται μεταβλήτες τύπους string.
    vector <string> data;
    string word;
    is.open("numbers.csv",ios::in);
    while(getline(is,line))
    {
        //getline συνάρτηση η οποία δεν διαβάζει το χαρακτήρα αλλαγής γραμμής από ένα αρχείο
        //Τύπος επιστροφής-->bool.
          if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
          //Error-->throws exeption--if(line[0]=='\n') continue;
        stringstream ss(line);
        data.clear();//Άδεισμα vector κάθε φορά που αλλάζει η γραμμή.
        while(getline(ss,word,','))//Για κάθε γραμμή θα γίνεται διαχωρισμός με βάση το ,
        {
            data.push_back(word);
            //Οι μεμονωμένες λέξεις θα αποθηκεύονται σε διάνυσμα με το όνομα data.
        }
        double average=0.0;
        for(vector <string>::iterator itr=data.begin();itr!=data.end();itr++)
        {
          string content=*itr;
          average+=stod(content);
        }
        average/=data.size();
        nums.push_back(average);
    }
    is.close();
}

void save_to_file(vector <double> &nums)
{
    ofstream out;
    out.open("results.out");
    out<<"Retrive data from csv file numbers.csv"<<endl;
    out<<"File results created at:"<<__DATE__<<"   "<<__TIME__<<endl;
    out<<"Results for every line retrieved from numbers.csv:::"<<endl;
    out<<endl;
    int cnt=1;
    for(vector <double>::iterator itr=nums.begin();itr!=nums.end();itr)
    {
        out<<"Average of line "<<cnt<<":"<<*itr<<endl;
        cnt++;
    }
    out.close();
}

int main(int argc,char **argv)
{
    vector <double> numbers;
    read_contents(numbers);
    save_to_file(numbers);
}