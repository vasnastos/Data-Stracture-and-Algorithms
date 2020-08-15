/*
Algorithms in STL-->H STL διαθέτει πληθώρα αλγορίθμων που μπορούν να εφαρμοστούν σε διάφορα προβλήματα. Για παράδειγμα, προκειμένου
να ταξινομηθούν δεδομένα μπορεί να χρησιμοποιηθεί η συνάρτηση sort της STL.

•sort()->Η συνάρτηση sort() εφαρμόζεται σε sequence containers πλην των list και forward_list στα οποία δεν μπορεί να γίνει απευθείας πρόσβαση σε στοιχεία τους χρησιμοποιώντας ακεραίους 
αριθμούς για τον προσδιορισμό της θέσης τους.[Τύπος επιστροφής-->void].
•binary_search()->Αναζήτηση στοιχείων σε έναν ταξιμομημένο πίνακα.[Τύπος επιστροφής-->bool]
•shuffle()->Ανακάτεμα στοιχείων μίας δομής με τυχαία μηχανή.[Τύπος επιστροφής-->void]
•max_element()->Επιστρέφει την θέση μνήμης του μεγίστου στοιχείου.[Τύπος επιστροφής-->Επιστρέφει διεύθυνση μνήμης].
•min_element()-> Επιστρέφει την θέση μνήμης του ελάχιστου στοιχείου.[Τύπος επιστροφής-->Επιστρέφει διεύθυνση μνήμης]
•accumulate()->Με βάση μία συνάρτηση βρίσκει το άθροισμα ενός πίνακα η μίας δομής.[Τύπος επιστροφής-->Τύπος στοιχείων του vector].
•find_if()->πραγματοποιεί αναζήτηση στο vector με βάση μία συνθήκη.
•count_if()->Προσμετράει στοιχεία από το vector με βάση μία συνθήκη.[Τύπος επιστροφής-->int]


ΑΣΚΗΣΗ:
  Να κατασκευαστεί πρόγραμμα το οποίο θα διαβάζει αριθμούς από ένα αρχείο και θα τους τοποθετεί σε vector με ακεραίους.
  Το πρόγραμμα να πραγματοποιεί τα ακόλουθα:
    •Να πραγματοποιεί εύρεση του αθροίσματος,του μέσου όρου,το μέγιστου και του ελάχιστου στοιχείου του διανύσματος.
    •Να ταξινομεί και να εμφανίζει τα στοιχεία της δομής.
    •Να πραγματοποιεί δυαδική αναζήτηση του αριθμού 12.
    •Να εμφανίζει το πλήθος των στοιχείων του vector.
    •Να εμφανίζει πόσα στοιχεία είναι μεγαλύτερα του 15.
    •Να πραγματοποιεί ανακάτεμα των τιμών του vector και να εμφανίζει τις τιμές του vector.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <algorithm>

using namespace std;

void read_data(vector <int> &data)
{
    string line;
    ifstream is;
    is.open("data.txt",ios::in);
    while(getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        int number=stoi(line);
        data.push_back(number);
    }
    is.close();
}

int sum(int &s,int &number)
{
    return s+number;
}

bool binary_search_results(vector <int> &v,int x)
{
    return binary_search(v.begin(),v.end(),x);
}

int main()
{
    vector <int> numbers;
    read_data(numbers);
    cout<<"************* REFERENCE ELEMENTS *********************"<<endl;
    cout<<"Sum of numbers:"<<accumulate(numbers.begin(),numbers.end(),0,sum)<<endl;
    cout<<"Average of numbers:"<<setprecision(5)<<accumulate(numbers.begin(),numbers.end(),0,sum)/(double)numbers.size()<<endl;
    cout<<"Max Element:"<<*max_element(numbers.begin(),numbers.end())<<endl;
    cout<<"Min Element:"<<*min_element(numbers.begin(),numbers.end())<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<endl;
    sort(numbers.begin(),numbers.end());
    cout<<"************* Numbers List After Sort *****************"<<endl;
    int i=1;
    for(auto &x:numbers)
    {
       cout<<"Element_"<<i<<":"<<x<<endl;
       i++;
    }
    cout<<"*********************************************"<<endl;
    cout<<endl;
    cout<<"Binary Search result for number 12"<<endl;
    if(binary_search_results(numbers,12))
    {
        cout<<"\tElement found!!!"<<endl;
    }
    else 
    {
        cout<<"Element did not found"<<endl;
    }
    cout<<"Size of vector:"<<numbers.size()<<endl;
    int number=15;
    int counter=count_if(numbers.begin(),numbers.end(),[number](const int &x) {return x>number;});
    cout<<"Numbers above "<<number<<":"<<counter<<endl;
    auto rng=default_random_engine{};
    shuffle(numbers.begin(),numbers.end(),rng);
    cout<<endl;
    cout<<"********** List Numbers after shuffle **************"<<endl;
    i=1;
    for(auto &x:numbers)
    {
       cout<<"Element_"<<i<<":"<<x<<endl;
       i++;
    }
    cout<<"*****************************************************"<<endl; 
    cout<<endl;  
}