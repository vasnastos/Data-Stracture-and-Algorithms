/*
Η βιβλιοθήκη STL (Standard Template Library) της C++ προσφέρει έτοιμη λειτουργικότητα για πολλά θέματα τα οποία
ανακύπτουν συχνά στον προγραμματισμό εφαρμογών. Πρόκειται για μια generic βιβλιοθήκη, δηλαδή κάνει εκτεταμένη χρήση
των templates.

H STL υποστηρίζει έναν αριθμό από containers στους οποίους μπορούν να αποθηκευτούν δεδομένα. Ένα από τα containers
είναι το vector (διάνυσμα).H δομή είναι δυναμική, δηλαδή το μέγεθος της μπορεί να μεταβάλλεται κατά
τη διάρκεια εκτέλεσης του προγράμματος
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec;
    for(int i=10;i<30;i+=2)
    {
        vec.push_back(i);
        //Συνάρτηση η οποία εισάγει ένα στοιχείο στο vector.
    }
    cout<<"Size of vector:"<<vec.size()<<endl;
    cout<<"************ List of Numbers ******************"<<endl;
    for(auto &x:vec)//Range for-->Τρόπος προσπέλασης τον στοιχείων μίας δομής
    {
       cout<<x<<endl;
    }
    cout<<"************************************************"<<endl;
    int pos;
    cout<<"Give position you want to erase";
    cin>>pos;
    vec.erase(vec.begin()+pos);//Διαγραφή στοιχείου από κάποια συγκεκρμένη θέση.
    cout<<"************ List of Numbers After erase ******************"<<endl;
    for(auto &x:vec)
    {
       cout<<x<<endl;
    }
    cout<<"************************************************************"<<endl;
    vec.insert(vec.begin()+3,17);//Εισαγωγή στην 3 θέση του αριθμού 17.
    cout<<"************ List Of Numbers After Insertion ******************"<<endl;
    for(auto &x:vec)
    {
       cout<<x<<endl;
    }
    cout<<"************************************************************"<<endl;
    vec.pop_back();//Εξαγωγή στοιχείου από την τελευταία θέση του vector.
    cout<<"************ List Of Numbers After Popback ******************"<<endl;
    for(auto &x:vec)
    {
       cout<<x<<endl;
    }
    cout<<"************************************************************"<<endl;
    cout<<vec.front()<<endl;//Στοιχείο στην πρώτη θέση του vector.
    vec.clear();//Άδειασμα vector.
    if(vec.empty())//ελέγχει αν το vector είναι άδειο.
    {
        cout<<"Empty Vector!!!!"<<endl;
    }
    vec.
}