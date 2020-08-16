/*Να γραφεί πρόγραμμα που να δέχεται μια φράση ως παράμετρο γραμμής εντολών (command line argument) 
και να εμφανίζει το εάν είναι παλινδρομική ή όχι. Μια φράση είναι παλινδρομική όταν διαβάζεται η ίδια από αριστερά προς τα δεξιά και
από δεξιά προς τα αριστερά.*/
#include <iostream>
#include <stack>


bool is_palindromic(std::string &word)
{
    std::stack <char> letters;
    for(char &x:word)
    {
        letters.push(x);
    }
    std::string compareword="";
    while(!letters.empty())
    {
        compareword+=letters.top();
        letters.pop();
    }
    return word==compareword;
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        std::cout<<"You did not insert an input word/phrase"<<std::endl;
        std::cout<<"SOFOS"<<"\t a Man a plan a canal a panama"<<std::endl;
        std::cout<<"Exit programm"<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::string keyword=argv[1];
    if(is_palindromic(keyword))
    {
        std::cout<<keyword<<" is palindromic"<<std::endl;
    }
    else 
    {
        std::cout<<keyword<<" is not palindromic"<<std::endl;
    }
}