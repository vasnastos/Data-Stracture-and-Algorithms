/*
H STL(standard template library) παρέχει υλοποιημένη την συνάρτηση 
δυαδικής αναζήτησης.
*/
#include <iostream>
#include <algorithm>//binary search,sort

int main()
{
    int board[5]={4,12,3,7,8};
    std::sort(board,board+5);//Ταξινόμιση του πίνακα κατα αύξουσα σειρά.
    int key=8;
    bool position=std::binary_search(board,board+5,key);//Δυαδική αναζήτηση για το στοιχείο 8
    if(position)
    {
        std::cout<<"Element "<<key<<" found in board"<<std::endl;
    }
    else 
    {
        std::cout<<"Element "<<key<<" did not found"<<std::endl;
    }
}
