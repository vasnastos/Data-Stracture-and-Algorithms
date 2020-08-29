/*
 Στον παρακάτω κώδικα πραγματοποιήται μία custom υλοποιήση των συναρτήσεων
 max_element,min_element.
*/
#include <iostream>
#include <iterator>

template <class T>T* max_element(T *start,T *end)
{
    T *max_value=start;
    for(auto itr=start+1;itr!=end;itr++)
    {
        if(*itr>*max_value)
        {
            max_value=itr;
        }
    }
    return max_value;
}

template <class T>T* min_element(T *start,T *end)
{
    T *min_value=start;
    for(auto itr=start+1;itr!=end;itr++)
    {
        if(*itr<*min_value)
        {
            min_value=itr;
        }
    }
    return min_value;
}

int main()
{
    int board[5]{67,4,5,8,12};
    double board2[5]{5.6,78.9,3.1,2.4,9.8};
    std::cout<<"Max of Board:"<<*max_element(board,board+5)<<std::endl;
    std::cout<<"Max of Board2:"<<*max_element(board2,board2+5)<<std::endl;
    std::cout<<"Min of Board:"<<*min_element(board,board+5)<<std::endl;
    std::cout<<"Min of Board2:"<<*min_element(board2,board2+5)<<std::endl;
    return 0;
}