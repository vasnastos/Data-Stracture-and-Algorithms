/*
Να γραφεί πρόγραμμα που να δέχεται ένα ακέραιο αριθμό ω και να εμφανίζει την ισοδύναμη δυαδική του μορφή.
Τα δεδομένα θα εισάγονται στο προγραμμα από αρχείο και θα εμφανίζονται τα αποτελέσματα της συνάρτησης για κάθε αριθμό 
που περιέχει το αρχείο.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

std::string to_binary(int number)
{
    std::stack <char> digits;
    int push=0;
    while(number!=0)
    {
        digits.push('0'+(number%2));
        number/=2;
        push++;
    }
    for(int j=push;j<8;j++)
    {
        digits.push('0');
    }
    std::string binary_number="";
    while(!digits.empty())
    {
        binary_number+=digits.top();
        digits.pop();
    }
    return binary_number;
}

int main()
{
    std::ifstream is;
    is.open("numbers(version 2).txt");
    int num;
    std::string line;
    int counter=0;
    while(std::getline(is,line))
    {
       std::cout<<counter<<" row results"<<std::endl;
       std::cout<<"Binary number:"<<line<<std::endl;
       std::cout<<"Decimal number:"<<to_binary(std::stoi(line))<<std::endl;
       std::cout<<std::endl;
       counter++;
    }
    is.close();
}