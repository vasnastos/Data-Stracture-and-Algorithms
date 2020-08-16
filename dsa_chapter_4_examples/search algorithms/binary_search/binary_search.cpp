/*
Υλοποίηση αλγόριθμου δυαδικής αναζήτησης.
Η δυαδική αναζήτηση πραγματοποιήται σε ταξινομημένους πίνακες.
Έστω πίνακας:board[5]={4,12,3,7,8}
Μετά την ταξινομιση:board[5]={3,4,7,8,12}
Δυαδική αναζήτηση για το 8
l->δείκτης που δείχνει στο αριστερό στοιχείο του πίνακα(Δείκτης στην πρώτη θέση).
r->δείκτης μία θέση μέτα το τελευταίο στοιχείο(δείκτης μία θέση μετά την τελευταία του πίνακα).
•Όσο l<=r τότε
•1η επανάληψη
l=0     r=5
   m=(l+r)/2
   m=2
    ________________________________
   |•εαν board[2]==8 επέστρεψε 2    |
   |•εαν board[2]<8  l=m+1          |
   |•εαν board[2]>8  r=m-1          |
   |________________________________|

-[board[2]=7]<8 
 ----> l=2+1=3
έλεγχος επανάληψης-->3<5

•2η επανάληψη
l=3     r=5
   m=4  
    ________________________________
   |•εαν board[4]==8 επέστρεψε 2    |
   |•εαν board[2]<8  l=m+1          |
   |•εαν board[2]>8  r=m-1          |
   |________________________________|

-[board[4]=12]>8
  ------>r=m-1
έλεγχος επανάληψης 3<=3

•3η επανάληψη
l=3      r=3
    m=3
    ________________________________
   |•εαν board[2]==8 επέστρεψε 2    |
   |•εαν board[2]<8  l=m+1          |
   |•εαν board[2]>8  r=m-1          |
   |________________________________|

-[board[3]=7]==7
 -------->επέστρεψε 3
 τέλος αλγορίθμου.
 */

#include <iostream>
#define GREATER 0//Σταθερά για αύξουσα ταξινόμιση.
#define LESS  1//Σταθερά για φθίνουσα ταξινόμιση.

//binary search
template <class T>int binary_search(T *a,T key,int left,int right)
{
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(a[middle]==key)
        {
            return middle;
        }
        else if(a[middle]<key)
        {
            left=middle+1;
        }
        else if(a[middle]>key)
        {
            right=middle-1;
        }
    }
    return -1;
}

//custom αλγόριθμος ταξινομισης πίνακα.(χρήση αλγορίθμου bubblesort).
template <class T>void sort(T *start,T *end,int flag=0)
{
    if(flag==0)
    {
      for(auto itr=start;itr!=end;itr++)
      {
          for(auto itrn=start;itrn!=end-1;itrn++)
          {
              if(*(itrn)>*(itrn+1))
              {
                 T value=*itrn;
                 *itrn=*(itrn+1);
                 *(itrn+1)=value;
              }
          }
      }
    }
    else
    {
       for(auto itr=start;itr!=end;itr++)
      {
          for(auto itrn=start;itrn!=end-1;itrn++)
          {
              if(*itrn<*(itrn+1))
              {
                 T value=*itrn;
                 *itrn=*(itrn+1);
                 *(itrn+1)=value;
              }
          }
      } 
    }
    
}

int main(int argc,char **argv)
{
   int board[5]{21,3,5,7,9};
   sort(board,board+5);
   if(argc!=3)
   {
       std::cerr<<"You did not provide 2 search numbers please give 2 search numbers!!!"<<std::endl;
       exit(EXIT_FAILURE);
   } 
   int position=binary_search(board,std::stoi(argv[1]),0,sizeof(board)/sizeof(board[0]));
   int position1=binary_search(board,std::stoi(argv[2]),0,sizeof(board)/sizeof(board[0]));
   if(position!=-1)
   {
       std::cout<<"Element "<<std::stoi(argv[1])<<" found at position "<<position<<std::endl;
   }
   else
   {
       std::cout<<"Element "<<std::stoi(argv[1])<<" did not found"<<std::endl;
   }
   if(position1!=-1)
   {
       std::cout<<"Element "<<std::stoi(argv[2])<<" found at position "<<position<<std::endl;
   }
   else 
   {
       std::cout<<"Element "<<std::stoi(argv[2])<<" did not found"<<std::endl;
   }   
}

/*
COMPILING:g++ binary_search.cpp -o binary
EXECUTION:binary 7 40
*/