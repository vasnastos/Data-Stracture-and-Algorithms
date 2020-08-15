/*
Map(λεξικό)-->Δομή κατακερματισμού. 
1ο στοιχείο-->key.
2o στοιχείο-->value.
-->ΑΣΚΗΣΗ:
#Να κατασκευαστεί πρόγραμμα το οποίο θα υλοποιεί την δομή ενός τηλεφωνικού καταλόγου με χρήση της κατάλληλης δομής 
 STL.Το πρόγραμμα θα πρέπει να εκτελεί τις ακόλουθες ενέργειες:
    1.Να μπορεί να εισάγει 1 εγγραφή στην δομή.
    2.Να μπορεί να πραγματοποεί αναζήτηση με βάση ένα όνομα στην δομή.
#Οι ενέργειες να πραγματοποιούνται επαναληπτικά.
#Το πρόγραμμα να εισάγει κατά την εκκίνηση του 3 εγγραφές.
       -Nikolaou,1234567890
       -vasileiou,2345678901
       -dimitriou,3456789012
*/

#include <iostream>
#include <map>
#include <pair>


//Κατασκευή μενού.
int main_menu()
{
    int ch;
    std::cout<<"1-Insert record"<<std::endl;
    std::cout<<"2-Search for record"<<std::endl;
    std::cout<<"3-Exit"<<std::endl;
    std::cout<<"4-Give choice:";
    std::cin>>ch;
    return ch;
}

int main()
{
    std::map <std::string,std::string> phonebook;
    //Εισαγωγή 3 custom values στο map.
    //1os τρόπος εισαγωγής.
    phonebook.insert(std::make_pair("nikolaou","1234567890"));
    //2os τρόπος εισαγωγής.
    phonebook["vasileiou"]="2345678901";
    //3οs τρόπος εισαγωγής.
    std::pair <std::string,std::string> p1=std::make_pair("dimitriou","3456789012");
    phonebook.insert(p1);
    std::string name;
    std::string phone;
    int c;
    while(true)
    {
        c=main_menu();
        if(c==1)
        {
           std::cout<<"Give new name:";
           std::cin>>name;
           std::cout<<"Give new phone:";
           std::cin>>phone;
        }
        else if(c==2)
        {
            std::cout<<"Give name:";
            std::cin>>name;
            if(phonebook.find(name)!=phonebook.end())
            {
                std::cout<<"Name:"<<name<<"\tPhone:"<<phonebook[name]<<std::endl;
            }
            else 
            {
                std::cout<<"Name:"<<name<<" did not found on the list"<<std::endl;
            }
        }
        else
        {
            exit(EXIT_SUCCESS);
        }       
    } 
}