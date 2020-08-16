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
#include <algorithm>
//για χρήση της συνάρτησης sort.

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
    std::cout<<"Element "<<key<<" did not found"<<std::endl;
    return -1;
}

int main()
{
    int board[5]={4,12,3,7,8};
    std::sort(board,board+5);//Ταξινόμιση του πίνακα κατα αύξουσα σειρά.
    int key=7;
    int position=binary_search(board,key,0,5);
    if(position!=-1)
    {
        std::cout<<"Element "<<key<<" found at position "<<position<<std::endl;
    }
}