/*
Να γραφεί πρόγραμμα που να δέχεται ένα δυαδικό αριθμό ως λεκτικό και να εμφανίζει την ισοδύναμη δεκαδική του μορφή.
Τα δεδομένα θα εισάγονται στο προγραμμα από αρχείο και θα εμφανίζονται τα αποτελέσματα της συνάρτησης για κάθε αριθμό 
που περιέχει το αρχείο.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

int to_decimal(std::string &dec)
{
    std::stack <char> digits;
    for(char &x:dec)
    {
        digits.push(x);
    }
    int multiplier;
    int step=1;
    int summary=0;
    while(!digits.empty())
    {
        multiplier=1;
        for(int i=1;i<step;i++)
        {
            multiplier*=2;
        }
        summary+=(digits.top()-'0')*multiplier;
        step++;
        digits.pop();
    }
    return summary;
}

int main()
{
    std::string decnum;
    std::ifstream is;
    std::string line;
    int i=1;
    is.open("numbers.txt",std::ios::in);
    while(std::getline(is,line))
    {
        std::cout<<i<<" row results::"<<std::endl;
         std::cout<<"Binary number:"<<line<<std::endl;
         std::cout<<"Decimal number:"<<to_decimal(line)<<std::endl;
         std::cout<<std::endl;
         i++;
    }
    is.close();
}