/*
Να κατασκευαστεί πρόγραμμα που θα δέχεται ένα λεκτικό και θα 
εμφανίζει τα μοναδικά γράμματα που περιέχονται σε αυτό το λεκτικό.
*/
/*
set=>Δέχεται τα στοιχεία μόνο μία φορά(Απορρίπτει διπλότυπα).
*/
#include <iostream>
#include <set>

int main()
{
    std::set <char> characters;
    std::string insertvalue;
    std::cout<<"Give Text:";
    std::cin>>insertvalue;
    for(int i=0;i<insertvalue.length();i++)
    {
        characters.insert(insertvalue.at(i));
    }
    std::cout<<"Distinct characters[";
    for(auto itr=characters.begin();itr!=characters.end();itr++)
    {
        std::cout<<*itr<<" ";
    }
    std::cout<<"]"<<std::endl;
}