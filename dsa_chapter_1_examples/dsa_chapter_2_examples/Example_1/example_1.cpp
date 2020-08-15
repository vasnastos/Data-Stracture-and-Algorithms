/*
Να γραφεί συνάρτηση εύρεσης ελαχίστου ανάμεσα σε τρεις αριθμούς.
Να εκτελεστεί η συνάρτηση για τρεις ακέραιους και τρεις δεκαδικούς αριθμούς.
*/

#include <iostream>
//Υλοποίηση χωρίς γενητικό προγραμματισμό 
int min(int a,int b,int c)
{
    int minelement=a;
    if(b<minelement)
    {
        minelement=b;
    }
    if(c<minelement)
    {
        minelement=c;
    }
    return minelement;
}

double min(double a,double b,double c)
{
    double minelement=a;
    if(b<minelement)
    {
        minelement=b;
    }
    if(c<minelement)
    {
        minelement=c;
    }
    return minelement;
}

/*
overloading-->Υπερφόρτωση συνάρτησης[Συνάρτηση με το ίδιο όνομα που γράφεται με δειαφορετικό τύπο επιστροφής και διαφορετικό αριθμό/τύπο 
ορισμάτων].
Εδώ απαραίτητη για να μπορέσω να υλοποιήσω συνάρτηση εύρεσης ελαχίστου για 2 τύπους δεδομένων.
*/

/*
Generic Programming-->Χρήση προτύπων για προγραμματισμό.
Η γλώσσα C++ είναι statically typed το οποίο σημαίνει ότι οι τύποι δεδομένων των μεταβλητών και σταθερών ελέγχονται κατά τη μεταγλώττιση.
Με τη χρήση των templates μπορεί να γραφεί κώδικας που να υποστηρίζει ταυτόχρονα πολλούς τύπους δεδομένων.
Ο μεταγλωττιστής αναλαμβάνει να δημιουργήσει όλες τις απαιτούμενες παραλλαγές των συναρτήσεων που θα
χρειαστούν στον κώδικα που μεταγλωττίζει.
*/

//template συνάρτηση εύρεσης ελαχίστου.Ο τύπος αποδίδεται από τον μεταγλωττιστή(Τ).
template <class T> T find_min(T a,T b,T c)
{
    T min=a;
    if(b<min)
    {
        min=b;
    }
    if(c<min)
    {
        min=c;
    }
    return min;
}

//Εκτέλεση αλγορίθμου για ακέραιους αριθμούς
void group_integer()
{
    int a,b,c;
    std::cout<<"Give first integer number:";
    std::cin>>a;
    std::cout<<"Give second integer number:";
    std::cin>>b;
    std::cout<<"Give third integer number:";
    std::cin>>c;
    int min_integer=find_min(a,b,c);
    std::cout<<"Min Element:"<<min_integer<<std::endl;
}

//Εκτέλεση συνάρτησης για δεκαδικούς αριθμούς
void group_float()
{
    float a,b,c;
    std::cout<<"Give first float number:";
    std::cin>>a;
    std::cout<<"Give second float number:";
    std::cin>>b;
    std::cout<<"Give third float number:";
    std::cin>>c;
    float min_integer=find_min(a,b,c);
    std::cout<<"Min Element:"<<min_integer<<std::endl;
}

int main()
{
    group_integer();
    group_float();
    return 0;
}