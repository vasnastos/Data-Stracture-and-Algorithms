/*
Έστω ένα παιχνίδι στο οποίο οι παίκτες έχουν όνομα (name) και επίδοση (score). Να γράψετε πρόγραμμα στο οποίο να
εισέρχονται στο παιχνίδι 10 παίκτες στη σειρά (player1, player2, ...), πετυχαίνοντας κάποια επίδοση ο καθένας (τυχαίος ακέραιος από το 0 μέχρι το 50.000). Να εμφανίζεται μετά την εισαγωγή του κάθε παίκτη ο παίκτης που προηγείται και η επίδοση
του. Τέλος, να εμφανίζονται τα ονόματα των παικτών με τις 3 υψηλότερες επιδόσεις.
*/
#include <iostream>
#include <queue>
#include <sstream>
#include <random>
#include <string>
#include <thread>
#define TOP 3

int seed()
{
    std::string st=__TIME__;
    std::string word;
    std::stringstream ss(st);
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

struct player
{
    std::string name;
    int score;
    bool operator<(const player &p)const {return score<p.score;}
};

int main()
{
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> dist(0,50000);
    std::priority_queue <player> pq;
    int best_score=-1;
    std::cout<<"*********** Additions form *********************"<<std::endl;
    for(int i=1;i<=10;i++)
    {
       player p;
       p.name="Player_"+std::to_string(i);
       p.score=dist(mt);
       pq.push(p);
       if(best_score!=pq.top().score)
       {
           best_score=pq.top().score;
       }  
       std::cout<<"New Addition:[Name:"<<p.name<<"    Score:"<<p.score<<"]==============>";
       std::cout<<"[best_score]:"<<pq.top().name<<"----------"<<best_score<<std::endl;
       std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"TOP 3 Players:::::"<<std::endl;
    player p[TOP];
    for(int i=0;i<TOP;i++)
    {
        std::cout<<i+1<<"."<<"Name:"<<pq.top().name<<"\tScore:"<<pq.top().score<<std::endl;
        p[i]=pq.top();
        pq.pop();
    }
    for(int i=0;i<TOP;i++)
    pq.push(p[i]);
    std::cout<<std::endl;
    std::cout<<"Final total elements:"<<pq.size()<<std::endl;
}