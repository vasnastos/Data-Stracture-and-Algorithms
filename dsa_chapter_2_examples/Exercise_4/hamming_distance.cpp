/*
Κατασκευάστε μια συνάρτηση που να επιστρέφει την απόσταση Hamming ανάμεσα σε δύο σειρές χαρακτήρων (η απόσταση
Hamming είναι το πλήθος των χαρακτήρων που είναι διαφορετικοί στις ίδιες θέσεις ανάμεσα στις δύο σειρές). Δημιουργήστε
ένα διάνυσμα με 100 τυχαίες σειρές μήκους 20 χαρακτήρων η κάθε μια χρησιμοποιώντας μόνο τους χαρακτήρες G,A,T,C.
Εμφανίστε το πλήθος από τις σειρές για τις οποίες υπάρχει τουλάχιστον μια άλλη σειρά χαρακτήρων με απόσταση Hamming
μικρότερη ή ίση του 10.
*/

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <sstream>
#include <tuple>

//Σπόρος που θα χρησιμοποιηθεί στην μηχανή mt19937
int seed()
{
    std::string time=__TIME__;
    std::string word;
    std::stringstream ss(time);
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

//Δημιουργία vector με τυχαίες γραμματοσειρές
void make_random_records(std::vector <std::string> &recs)
{
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> letterschoose(0,3);
    char letters[]{'G','A','T','C'};
    std::string word;
    for(int i=0;i<100;i++)
    {
        word="";
        for(int i=0;i<20;i++)
        {
            word+=letters[letterschoose(mt)];
        }
        recs.push_back(word);
    }
}

//Υπολογισμός απόστασης hamming ανάμεσα σε 2 γραμματοσειρές
int hamming_distance(std::string &w1,std::string &w2)
{
    int counter=0;
    for(int i=0;i<w1.size();i++)
    {
        if(w1.at(i)==w2.at(i))
        {
            counter++;
        }
    }
    return counter;
}

//Υπολογισμός γραμματοσειρών που έχουν απόσταση hamming παραπάνω από 10 με μία γραμματοσειρά η περισσότερες.
std::map <std::string,int> get_over_10(std::vector <std::tuple<std::string,std::string,int>> &r,std::vector <std::string> &rec)
{
    std::map <std::string,int> over;
    for(auto &x:rec)
    {
        int counter=0;
        for(auto &y:r)
        {
           if(x==std::get<0>(y))
           {
               if(std::get<2>(y)>=10) counter++;
           }
        }
        if(counter>=1)
        {
            over[x]=counter;
        }
    }
    return over;
}

//Υπολογισμός απόστασης hamming για όλες τις γραμματοσειρές
std::vector<std::tuple <std::string,std::string,int>> calculate_hamming_distance(std::vector <std::string> &recs)
{
  std::vector<std::tuple <std::string,std::string,int>> hamming;
  for(int i=0;i<recs.size();i++)
  {
      for(int j=0;j<recs.size();j++)
      {
          if(i==j) continue;
          std::tuple <std::string,std::string,int> newrecord=std::make_tuple(recs[i],recs[j],hamming_distance(recs[i],recs[j]));
          hamming.push_back(newrecord);
      }
  }
  return hamming;
}

int main()
{
    std::vector <std::string> records;
    make_random_records(records);
    std::vector<std::tuple <std::string,std::string,int>> hamming_distances=calculate_hamming_distance(records);
    for(auto &x:records)
    {
        std::cout<<"************ Hamming Diastances for string "<<x<<" ********************"<<std::endl;
        for(auto &y:hamming_distances)
        {
            if(x==std::get<0>(y))
            {
                std::cout<<std::get<1>(y)<<"--"<<std::get<2>(y)<<std::endl;
            }
        }
        std::cout<<"*************************************************************************"<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<"*********** Series with at least one hamming distance over 10 ***************"<<std::endl;
    std::map <std::string,int> over10=get_over_10(hamming_distances,records);
    for(std::map <std::string,int>::iterator itr=over10.begin();itr!=over10.end();itr++)
    {
        std::cout<<itr->first<<"--"<<itr->second<<std::endl;
    }
    std::cout<<"******************************************************************************"<<std::endl;
}