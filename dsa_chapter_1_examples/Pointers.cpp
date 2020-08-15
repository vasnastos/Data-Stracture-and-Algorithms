/*
Pointers in c++
Author Nastos Vasileios
11/07/2020
*/
#include <iostream>
//#include <cstdlib>-->for functions malloc and free.

int main(int argc,char **argv)
{
    int *p;//Δεν έχει τιμή o δεικτής p.
    //Δεν δείχνει σε κάποια διεύθυνση μνήμης(στατική η δυναμική).
    //c dynamic allocation of memory
    //p=(int *)malloc(sizeof(int));-->Δυναμική δέσμευση μνήμης για τον δείκτη p.
    //p=new int(3);-->Ο Δείκτης p δεσμέυει μία θέση μνήμης που έχει περιεχόμενο την τιμή 3.
    p=new int;
    *p=2;
    std::cout<<"Value of p:"<<*p<<std::endl;
    //Αποδέσμευση της μνήμης που δέσμευσε ο δείκτης.
    //free(p);
    delete p;
    return 0;
}