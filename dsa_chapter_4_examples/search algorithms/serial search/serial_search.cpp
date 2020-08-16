/*
Στον παρακάτω κώδικα πραγματοποήται η υλοποιήση του αλγορίθμου σειριακής αναζήτησης.
Ο αλγόριθμος προσπελάυνει ένα ένα τα στοιχεία του πίνακα μέχρι να βρει το επυθημιτό στοιχείο
Πολυπλοκότητα Ο(Ν)
Η παρακάτω υλοποιήση πραγματοποιήται σε μία template συνάρτηση άρα είναι υλοποίηση για πίνακες που 
περιέχουν διάφορους τύπος δεδομένων.
*/
#include <iostream>
#include <random>
#include <numeric>
#include <sstream>
#include <vector>

//Συνάρτηση σειριακής αναζήτης που επιστρέφει την θέση του αναζητούμενου στοιχείου.
template <typename T>int serial_search(T *a,int size,T keyvalue)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(a[i]==keyvalue)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

//-----------------------------------------------------------
//Συνάρτηση παραγωγής σπόρου για κατασκευή μηχανής τυχαίων αριθμών
unsigned int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    std::vector <std::string> timein;
    while(std::getline(ss,word,':'))
    {
       timein.push_back(word);
    }
    return (std::stoi(timein[0])+std::stoi(timein[1])+std::stoi(timein[2]))/timein.size();
}
//-----------------------------------------------------------

int main(int argc,char **argv)
{
    //Παροχή τιμών αναζήτης από command line arguments
    if(argc<2)
    {
        std::cerr<<"No argument in order to make serial search"<<std::endl;
        exit(EXIT_FAILURE);
    }

    //Γέμισμα πινάκων με τυχαίες τιμές
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> size(1,20);
    std::uniform_int_distribution <int> integers(1,200);
    std::uniform_real_distribution <double> floats(1.0,200.0);
    int board[size(mt)];
    double pin[size(mt)];
    for(int i=0;i<sizeof(board)/sizeof(board[0]);i++)
    {
        board[i]=integers(mt);
    }
    for(int i=0;i<sizeof(pin)/sizeof(pin[0]);i++)
    {
        pin[i]=floats(mt);
    }

    //Εκτύπωση στοιχείων πινάκων
    std::cout<<"     Integers Board   "<<std::endl;
    for(int i=0;i<sizeof(pin)/sizeof(pin[0]);i++)
    {
        std::cout<<"BOARD["<<i<<"]:"<<board[i]<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"     Doubles Board    "<<std::endl;
    for(int i=0;i<sizeof(pin)/sizeof(pin[0]);i++)
    {
        std::cout<<"Pin["<<i<<"]:"<<pin[i]<<std::endl;
    }
    
    /*
    Πραγματοποίηση αναζήτησης με βάση τα ορίσματα της γραμμής εντολών.
    */
    for(int i=1;i<argc;i++)
    {
        if(i%2!=0)
        {
            int position=serial_search(board,sizeof(board)/sizeof(board[0]),std::stoi(argv[i]));
            if(position!=-1)
            {
                std::cout<<"Element "<<std::stoi(argv[i])<<" found at position "<<position<<std::endl;
            }
            else 
            {
                std::cout<<"Element "<<std::stoi(argv[i])<<" did not found"<<std::endl;
            }
        }
        else
        {
            int position=serial_search(pin,sizeof(pin)/sizeof(pin[0]),std::stod(argv[i]));
            if(position!=-1)
            {
                std::cout<<"Element "<<std::stod(argv[i])<<" found at position "<<position<<std::endl;
            }
            else 
            {
                std::cout<<"Element "<<std::stod(argv[i])<<" did not found"<<std::endl;
            }
        }       
    }
}

/*Παροχή τιμών από γραμμή εντολών
COMPILING:g++ serial_search.cpp -o serial

EXECUTION:serial 21 3.4 2 6.5 8 2.1 4
argv[0]="Serial";
argv[1]="21"                    ____________________________________________________
argv[2]="3.4"                  | Μετρητής τιμών που δόθηκαν από την γραμμή εντολών. |
argv[3]="0"                    |                      argc=8                        |
argv[4]="2.6"                  |____________________________________________________| 
argv[5]=8
argv[6]="2.1"
argv[7]="4"
*/