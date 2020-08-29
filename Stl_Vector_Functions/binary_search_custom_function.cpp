/*
   Στον παρακάτω κώδικα ακολουθεί μία custom υλοποίηση της συνάρτησης
   binary_search()[Δυαδική αναζήτηση] καθώς και μία custom της συνάρτησης ταξινόμισης. 
*/

#include <iostream>
#include <iterator>

template <class T>void sort(T *start,T *end)
{
    T temp;
    for(auto itr=start;itr!=end;itr++)
    {
        for(auto itrn=start;itrn!=end-1;itrn++)
        {
            if(*itrn>*(itrn+1))
            {
                temp=*itrn;
                *itrn=*(itrn+1);
                *(itrn+1)=temp;
            }
        }
    }
}

template <class T>bool binary_search(T *start,T *end,T key)
{
    int left=start-start;
    int right=end-start;
    int middle;
    while(left<=right)
    {
        middle=(left+right)/2;
       if(*(start+middle)==key)
       {
          return true;
       }
       else if(*(start+middle)>key)
       {
           right=middle-1;
       }
       else if(*(start+middle)<key)
       {
          left=middle+1;
       }
    }
    return false;
}

int main()
{
    int board[6]{5,6,23,7,12,18};
    double brd[6]{6.7,8.9,34.5,12.7,1.9,4.5};
    sort(board,board+6);
    sort(brd,brd+6);
    if(binary_search(board,board+6,11))
    {
        std::cout<<"Element 11 found"<<std::endl;
    }
    else
    {
        std::cout<<"Element 11 did not found"<<std::endl;
    } 
    if(binary_search(brd,brd+6,1.9))
    {
      std::cout<<"Element 1.9 found"<<std::endl;
    }   
    else 
    {
        std::cout<<"Element 1.9 did not found"<<std::endl;
    }
}