/*
  Να κατασκευαστεί πρόγραμμα στο οποίο ο χρήστης θα δίνει ένα δεκαδικό αριθμό και θα τον μετατρέπει στον αντίστοιχο 
  δεκαεξαδικό καθώς και στον αντιστοιχο 2-αδικό.Η τιμη θα δίνεται σαν μεταβλητη γραμμής εντολών.
*/
#include <iostream>
#include <stack>
#include <string>
std::string to_hexadecimal(int dec)
{
    std::stack <char> digits;
    if(dec==16)
    {
        return "10";
    }
    while(dec!=0)
    {
       int rest=dec%16;
       if(rest>=10 && rest<=15)
       {
           digits.push('A'+rest-10);
       }
       else
       {
           digits.push(rest+'0');
       }
       dec/=16;
    }
    std::string num="";
    while(!digits.empty())
    {
        num+=digits.top();
        digits.pop();
    }
    return num;
}

int to_decimal(std::string n)
{
    int decimal=0;
    int j=1;
    std::stack <char> digits;
    for(int i=0;i<n.size();i++)
    {
        digits.push(n.at(i));
    }
    decimal+=digits.top()*j;
    while(!digits.empty())
    {
       digits.pop();
       j*16;
       decimal+=digits.top()*j;
    }
    return decimal;
}

std::string to_binary(int dec)
{
    std::stack <char> digits;
    while(dec!=0)
    {
        digits.push(dec%2+'0');
        dec/=2;
    }
    std::string n="";
    while(!digits.empty())
    {
        n+=digits.top();
        digits.pop();
    }
    return n;
}

int main(int argc,char **argv)
{
   if(argc<2)
   {
       std::cerr<<"Wrong amount of arguments!!!"<<std::endl;
       return 0;
   }
   for(int i=1;i<argc;i++)
   {
       std::cout<<"Decimal Number:"<<std::stoi(argv[i])<<std::endl;
        std::cout<<"Hex Value:"<<to_hexadecimal(std::stoi(argv[i]))<<std::endl;
        std::cout<<"Binary:"<<to_binary(std::stoi(argv[i]))<<std::endl;
   } 
}