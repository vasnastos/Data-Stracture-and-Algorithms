/*
Να γραφεί συνάρτηση που να δέχεται ως παράμετρο έναν πίνακα ακεραίων και έναν ακέραιο αριθμό κ και να επιστρέφει
το κ­οστό μεγαλύτερο στοιχείο του πίνακα.
Να κατασκευαστεί ένας πίνακας 10 θέσεων με τυχαίες τιμές και αποθηκευτούν τα αποτελέσματα σε αρχείο results.out
για k=1,k=3 και k=8. 
*/

#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <fstream>


int seed()
{
    std::string t=__TIME__;
    std::stringstream split(t);
    std::string word;
    while(std::getline(split,word,':'))
    {

    }
    return std::stoi(word);
}

int k_val(int *a,int size,int k)
{
    if(k<0 || k>=size)
    {
        throw "invalid position";
        return 0;
    }
    std::priority_queue <int,std::vector <int>,std::greater <int>> pq;
    for(int i=0;i<size;i++)
    {
       pq.push(a[i]);
    }
    for(int i=0;i<k-1;i++)
    {
        pq.pop();
    }
    return pq.top();
}

int main()
{
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> num(0,1900);
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=num(mt);
    }
    std::ofstream out;
    out.open("results.out",std::ios::out);
    out<<"Results sheet created at:"<<__TIME__<<"---"<<__DATE__<<std::endl;
    out<<"Cheked values:k=1    k=3      k=8"<<std::endl;
    out<<"For k=1  1st max_value:"<<k_val(a,sizeof(a)/sizeof(a[0]),1)<<std::endl;
    out<<"For k=3  3rd max_value:"<<k_val(a,sizeof(a)/sizeof(a[0]),3)<<std::endl;
    out<<"For k=8  8th max_value:"<<k_val(a,sizeof(a)/sizeof(a[0]),8)<<std::endl;
    out<<"Datasheet results ended"<<std::endl;
    out<<"Usage for charter 7 heaps"<<std::endl;
    out<<"Created by Nastos Vasileios(Arta-Informatics and telecommunications department)"<<std::endl;
    out.close();
}