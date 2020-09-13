/*
Γράψτε ένα πρόγραμμα που να δημιουργεί ένα απλό blockchain. 
Το blockchain είναι μια αλυσίδα από μπλοκς για τα οποία ισχύει ότι το hash του προηγούμενου 
μπλοκ καταγράφεται ως πληροφορία στο τρέχον μπλοκ. Υλοποιήστε το blockchain σύμφωνα με τις ακόλουθες οδηγίες:
Κάθε μπλοκ του blockchain να είναι ένα struct που να αποτελείται από 
τα εξής στοιχεία: id (τύπου size_t), timestamp (τύπου string), data (τύπου string), nonce (τύπου size_t) και previous_hash (τύπου size_t).
Να γράψετε συνάρτηση size_t hash_combined(block &a_block) που να επιστρέφει το hash 
ενός μπλοκ ως hash του λεκτικού που προκύπτει από τη συνένωση ως ένα λεκτικό των επιμέρους στοιχείων του μπλοκ. 
Για τον υπολογισμό του hash του λεκτικού να χρησιμοποιηθεί η std::hash.
Να γράψετε συνάρτηση void find_nonce(block &a_block, int difficulty) που να αλλάζει την τιμή του πεδίου nonce του a_block 
(ξεκινώντας από το 0 και δοκιμάζοντας διαδοχικά τιμές που αυξάνονται κατά 1) έτσι ώστε η hash τιμή του block να έχει 
τόσα συνεχόμενα μηδενικά στο τέλος όσα η τιμή της μεταβλητής difficulty.
Το αρχικό μπλοκ να έχει τα εξής στοιχεία: {0, <τρέχουσα ημερομηνία και ώρα>, “GENESIS BLOCK”,, 0} 
και να τοποθετείται σε μια std::list της STL.
Η <τρέχουσα ημερομηνία και ώρα> να καταγράφεται ως YYYY-MM-DD HH:MM:SS. 
Το nonce να υπολογίζεται με difficulty=7.
Να συμπληρωθούν 7 επιπλέον μπλοκς έτσι ώστε το blockchain το οποίο θα έχει δημιουργηθεί με difficulty=7 να 
περιέχει πληροφορία αντίστοιχη με την ακόλουθη.

id: 0 
    ts: 2019-12-01 12:37:15 
    data: GENESIS block 
    nonce: 7705472
    p_hash: 0
    hash: 7409222825570000000

    id: 1 
    ts: 2019-12-01 12:37:24 
    data: Alice pays 10 euros to Bob 
    nonce: 20662197 
    p_hash: 7409222825570000000 
    hash: 14415237325170000000

    id: 2 
    ts: 2019-12-01 12:37:55 
    data: Bob pays 5 euros to Carl 
    nonce: 4180543 
    p_hash: 14415237325170000000 
    hash: 9785420976540000000

    id: 3 
    ts: 2019-12-01 12:38:02 
    data: Carl pays 10 euros to David 
    nonce: 3124703 
    p_hash: 9785420976540000000 
    hash:15500881473790000000

    id: 4 ts:2019-12-01 12:38:07 
    data: David pays 2 euros to Alice 
    nonce: 11311765 
    p_hash: 15500881473790000000 
    hash:17403203628000000000

    id: 5 
    ts: 2019-12-01 12:38:24 
    data: Alice pays 2 euros to Bob 
    nonce: 28602793 
    p_hash: 17403203628000000000 
    hash:847005160950000000

    id: 6 
    ts: 2019-12-01 12:39:08 
    data: Bob pays 5 euros to David 
    nonce: 5567229 
    p_hash: 847005160950000000 
    hash:10509950750660000000

    id: 7 
    ts: 2019-12-01 12:39:17 
    data: Carl pays 5 euros to Alice 
    nonce: 6164283 
    p_hash: 10509950750660000000 
    hash:11846123523500000000

Να γράψετε συνάρτηση bool check_valid_blockchain(list &chain) που 
να επιστρέφει εάν το blockchain είναι έγκυρο ή όχι, εξετάζοντας την καταγεγραμμένη τιμή του previous_hash σε κάθε 
μπλοκ με την hash τιμή του προηγούμενου μπλοκ. Ελέγξτε την εγκυρότητα του blockchain.
Αλλάξτε το προτελευταίο block έτσι ώστε να περιέχει ως data το κείμενο «Bob pays 5000 euros to David» και 
ελέγξτε εκ νέου την εγκυρότητα του blockchain.
*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <random>

struct block
{
    size_t id;
    std::string timestamp;
    std::string data;
    size_t nonce;
    size_t previous_hash;
};

size_t hash_combined(block &ablock)
{
    std::string blockstring=ablock.data+std::to_string(ablock.id)+ablock.timestamp+std::to_string(ablock.nonce)+std::to_string(ablock.previous_hash);
    std::hash <std::string> hs;
    return hs(blockstring);
}

void find_nonce(block &ablock,int difficulty)
{
  while(true)
  {
      std::string data=std::to_string(hash_combined(ablock));
      int counter=0;
      for(int i=data.length()-1;i>=data.length()-difficulty;i--)
      {
          if(data.at(i)=='0')
          {
              counter++;
          }
      }
      if(counter==difficulty)
      {
          break;
      }
      ablock.nonce++;
  }
  std::cout<<"out"<<std::endl;
}

bool valid_chain(std::list <block> &s)
{
    int counter=0;
    block previousblock;
   for(auto itr=s.begin();itr!=s.end();itr++)
   {
       if(itr==s.begin())
       {
           if(itr->previous_hash==0)
           {
               counter++;
           }
       }
       else
       {
           if(itr->previous_hash==hash_combined(previousblock))
           {
               counter++;
           }
       }
       previousblock=*itr;
   }  
   return counter==s.size();
}

void savewordpad(std::list <block> &bls)
{
    std::ofstream os;
    std::string line,fn;
    std::cout<<"Give filename:";
    std::cin>>fn;
    os.open(fn,std::ios::out);
    os<<"DATE:"<<__DATE__<<"    TIME"<<__TIME__<<std::endl;
    os<<"List of BlockChain document with all the data"<<std::endl<<std::endl;
    for(auto itr=bls.begin();itr!=bls.end();itr++)
    {
        os<<"Id:"<<itr->id<<std::endl;
        os<<"Data:"<<itr->data<<std::endl;
        os<<"Nonce:"<<itr->nonce<<std::endl;
        os<<"TimeStamp:"<<itr->timestamp<<std::endl;
        os<<"Previous Hash:"<<itr->previous_hash<<std::endl;
        os<<"Hash:"<<hash_combined(*itr)<<std::endl<<std::endl;
    }
    if(valid_chain(bls))
    {
        os<<"Valid BlockChain"<<std::endl<<std::endl;
    }
    else
    {
        os<<"InvalidBlockChain"<<std::endl<<std::endl;
    }
    auto myitr=bls.rbegin();
    myitr++;
    myitr->data="Bob pays 5000 euros to David";
    for(auto itr=bls.begin();itr!=bls.end();itr++)
    {
        os<<"Id:"<<itr->id<<std::endl;
        os<<"Data:"<<itr->data<<std::endl;
        os<<"Nonce:"<<itr->nonce<<std::endl;
        os<<"TimeStamp:"<<itr->timestamp<<std::endl;
        os<<"Previous Hash:"<<itr->previous_hash<<std::endl;
        os<<"Hash:"<<hash_combined(*itr)<<std::endl<<std::endl;
    }
    if(valid_chain(bls))
    {
        os<<"Valid BlockChain"<<std::endl<<std::endl;
    }
    else
    {
        os<<"Invalid BlockChain"<<std::endl<<std::endl;
    }
    os.close();
}

int main()
{
    std::list <block> blocks;
    std::string data[]{"GENESIS block","Alice pays 10 euros to Bob","Bob pays 5 euros to Carl","Carl pays 10 euros to David","David pays 2 euros to Alice","Alice pays 2 euros to Bob","Bob pays 5 euros to David","Carl pays 5 euros to Alice"};
    int size=sizeof(data)/sizeof(data[0]);
    for(int i=0;i<size;i++)
    {
        std::string date=__DATE__;
        std::string time=__TIME__;
        block ablock{i,date+" "+time,data[i],0,0};
        blocks.push_back(ablock);
    }
    block previous_hash;
    for(auto itr=blocks.begin();itr!=blocks.end();itr++)
    {
            find_nonce(*itr,7);
            if(itr==blocks.begin())
            {
                itr->previous_hash=0;
            }
            else
            {
                itr->previous_hash=hash_combined(previous_hash);
            }
            previous_hash=*itr;
    }
    for(auto itr=blocks.begin();itr!=blocks.end();itr++)
    {
        std::cout<<"id:"<<itr->id<<std::endl;
        std::cout<<"data:"<<itr->data<<std::endl;
        std::cout<<"TimeStamp"<<itr->timestamp<<std::endl;
        std::cout<<"Nonce:"<<itr->nonce<<std::endl;
        std::cout<<"Previous Hash:"<<itr->previous_hash<<std::endl;
        std::cout<<"Hash:"<<hash_combined(*itr)<<std::endl<<std::endl;
    }
    if(valid_chain(blocks))
    {
        std::cout<<"BlockChain is Valid"<<std::endl;
    }
    else
    {
        std::cerr<<"Invalid BlockChain"<<std::endl;
    }
    int choice;
    std::cout<<"Save BlockChain results to wordpad(0,yes|1,No):";
    std::cin>>choice;
    if(choice==0)
    {
        savewordpad(blocks);
    }
    auto myitr=blocks.rbegin();
    myitr++;
    myitr->data="Bob pays 5000 euros to David";
    for(auto itr=blocks.begin();itr!=blocks.end();itr++)
    {
        std::cout<<"id:"<<itr->id<<std::endl;
        std::cout<<"data:"<<itr->data<<std::endl;
        std::cout<<"TimeStamp"<<itr->timestamp<<std::endl;
        std::cout<<"Nonce:"<<itr->nonce<<std::endl;
        std::cout<<"Previous Hash:"<<itr->previous_hash<<std::endl;
        std::cout<<"Hash:"<<hash_combined(*itr)<<std::endl<<std::endl;
    }
    if(valid_chain(blocks))
    {
        std::cout<<"BlockChain is Valid"<<std::endl;
    }
    else
    {
        std::cerr<<"Invalid BlockChain"<<std::endl;
    }   
    return 0;
}