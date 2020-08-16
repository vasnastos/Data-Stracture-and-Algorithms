/*
Να κατασκευαστεί πρόγραμμα στο οποίο ο χρήστης θα δημιουργεί ένα πίνακα 10 θέσεων με τυχαίες ακέραιες τιμές[Εύρους 1 εως 200].Στην συνέχεια να
εμφανίζονται η τιμές του πίνακα ανάποδα.
*/
#include <iostream>
#include <random>
#include <sstream>
#include <stack>

int seed()
{
   std::string time=__TIME__;
   std::string word;
   std::stringstream ss(time);
   while(std::getline(ss,word,':')) {
       //do nothing
    }
    return std::stoi(word);
}

int main(int argc,char **argv)
{
    std::mt19937 mac(seed());
    std::uniform_int_distribution <int> dist(1,200);
    int board[10];
    for(int i=0;i<10;i++)
    {
      board[i]=dist(mac);
    }
    std::stack <int> reverse;
    std::cout<<"Board"<<std::endl;
    for(int i=0;i<10;i++)
    {
        reverse.push(board[i]);
        std::cout<<board[i]<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Reverse Board"<<std::endl;
    while(!reverse.empty())
    {
        std::cout<<reverse.top()<<std::endl;
        reverse.pop();
    }
}