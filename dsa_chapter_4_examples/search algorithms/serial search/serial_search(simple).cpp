/*
  Απλός κώδικας σειριακής αναζήτησης
*/

#include <iostream>

template <typename T>int serial_search(T *a,int size,T keyvalue)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(a[i]==keyvalue)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

template <class T>void show_result(int position,T value)
{
    if(position!=-1)
    {
        std::cout<<"Element "<<value<<" found at position "<<position<<std::endl;
    }
    else 
    {
        std::cout<<"Element "<<value<<" did not found"<<std::endl;
    }
}

int main()
{
    int board[7];
    double pin[7];
    int j=0;
    for(int i=3;i<=9;i++)
    {
         board[j]=i;
         j++;
    }
    j=0;
    for(double i=12.5;i<15;i+=0.5)
    {
        pin[j]=i;
        j++;
    }
    int pos1=serial_search(board,7,6);
    int pos2=serial_search(board,7,2);
    int pos3=serial_search(pin,7,13.5);
    int pos4=serial_search(pin,7,12.4);
    show_result(pos1,6);
    show_result(pos2,2);
    show_result(pos3,13.5);
    show_result(pos4,12.4);
}