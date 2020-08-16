/*
 Να κατασκευαστεί πρόγραμμα που θα διαβάσει από αρχείο δεδομένα για εκλογές(όνομα κόμματος,ψήφοι).
 Το προγραμμα θα πρέπει να εμφανιζει ταξινομημένα τα ποσοστά των αποτελεσματων των εκλογών. 
*/
#include "driver.hpp"
#include <algorithm>

int main()
{
    std::vector <election> elections;
    open_file(elections);
    std::cout<<"********** SUMMARY OF VOTES *****************"<<std::endl;
    for(auto &x:elections)
    {
        std::cout<<"Name:"<<x.get_name()<<"\tVotes:"<<x.get_votes()<<std::endl;
    }
    std::cout<<"**********************************************"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"********** Sorted Percents *******************"<<std::endl;
    sort(elections.begin(),elections.end(),[](const election &e1,const election &e2) {return e1.get_votes()>e2.get_votes();});
    std::map <std::string,double> prcs=precents(elections);
    for(std::map<std::string,double>::iterator itr=prcs.begin();itr!=prcs.end();itr++)
    {
        std::cout<<"Party:"<<itr->first<<"\t"<<"Percent:"<<itr->second<<std::endl;
    }
    std::cout<<"*************************************************"<<std::endl;
    return 0;
}

/*
Go to the directory you have store the source codes.
Compile:g++ driver.cpp election.cpp exercise3.cpp -o exercise3
Run:exercise3
*/