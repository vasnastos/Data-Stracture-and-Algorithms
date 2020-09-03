/*
Ο κατακερματισμός είναι μια μέθοδος που επιτυγχάνει ταχύτατη αποθήκευση, αναζήτηση και διαγραφή δεδομένων. Σε
ένα σύστημα κατακερματισμού τα δεδομένα αποθηκεύονται σε έναν πίνακα που ονομάζεται πίνακας κατακερματισμού (hash
table). Θεωρώντας ότι τα δεδομένα είναι εγγραφές που αποτελούνται από ζεύγη τιμών της μορφής κλειδί­τιμή, η βασική ιδέα
είναι, ότι εφαρμόζοντας στο κλειδί κάθε εγγραφής που πρόκειται να αποθηκευτεί ή να αναζητηθεί τη λεγόμενη συνάρτηση
κατακερματισμού (hash function), προσδιορίζεται μονοσήμαντα η θέση του πίνακα στην οποία τοποθετούνται τα δεδομένα
της εγγραφής. Η συνάρτηση κατακερματισμού αναλαμβάνει να αντιστοιχήσει έναν μεγάλο αριθμό ή ένα λεκτικό σε ένα μικρό
ακέραιο που χρησιμοποιείται ως δείκτης στον πίνακα κατακερματισμού.
Στο παρακάτω παράδειγμα παρασουσιάζεται μία απλή υλοποιήση μίας συνάρτησης κατακερματισμού.Πραγματόποιηται ανάκτηση 
πέντε λεκτικών από ένα αρχείο hash_example.txt και τοποθήτηση τους σε ένα πίνακα με βάση μία hash function.
*/
#include <iostream>
#include <set>
#include <fstream>
#include <thread>
#include <cmath>
#include <algorithm>
#include <sstream>
#define HT_SIZE 5

size_t hash(std::string key)
{
    size_t h=0;
    for(int i=0;i<key.length();i++)
    {
        h+=sqrt(key.at(i));
    }
    return h;
}

int main()
{
    std::string board[5];
    std::set <int> positions;
   std::ifstream is;
   std::string line;
   int collisions=0;
   is.open("hash_example.txt",std::ios::in);
   while(std::getline(is,line))
   {
       size_t realval=hash(line);
       int collisionsmade=0;
       if(line.size()==0) continue;
       if(line.at(0)=='#') continue;
       int tablepos=realval%HT_SIZE;
       while(positions.find(tablepos)!=positions.end())
       {
           std::string newkey="";
           char k='A'+collisionsmade;
           newkey+=k;
           tablepos=hash(newkey)%HT_SIZE;
           collisionsmade++;
       }
       positions.insert(tablepos);
       collisions+=collisionsmade;
       board[tablepos]=line;
       std::cout<<"****************************************************************"<<std::endl;
       std::cout<<"#"<<realval<<"->"<<tablepos<<"\tBoard["<<tablepos<<"]:"<<board[tablepos]<<std::endl;
       std::cout<<"Collisions in this->procudure:"<<collisionsmade<<std::endl;
       std::cout<<"****************************************************************"<<std::endl<<std::endl;
       std::this_thread::sleep_for(std::chrono::seconds(4));
   }
   is.close();
   std::cout<<"#######################################################"<<std::endl;
   std::cout<<"Total collisions made:"<<collisions<<std::endl;
   std::cout<<"#######################################################"<<std::endl<<std::endl;
   std::cout<<"Board summary::"<<std::endl;
   for(auto itr=board;itr!=board+HT_SIZE;itr++)
   {
       std::cout<<"Board["<<itr-board<<"]:"<<*itr<<std::endl;
   }
}