/*
  Παρόμοια οι συναρτήσεις max_element και min_element μπορούν να χρησιμοποιηθούν και σε πίνακες.
  Στον παρακάτω κώδικα χρησιμοποιούνται οι 2 συναρτήσεις για εύρεση μεγίστου και ελαχίστου του 
  πίνακα.
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int board[5]={6,12,45,6,3};
    std::cout<<"Min:"<<*std::min_element(board,board+5)<<std::endl;
    std::cout<<"Max:"<<*std::max_element(board,board+5)<<std::endl;
    return 0;
}