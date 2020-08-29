/*
   Έτοιμη συνάρτηση η οποία πραγματοποιεί δυαδική αναζήτηση σε ένα δυάνισμα για να 
   βρει τα στοιχεία του.
   Στον παρακάτω κώδικα πραγματοποιήται δυαδική αναζήτηση για τον αριθμό 6.
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector <int> vec;
    for(int i=0;i<10;i++)
    {
      vec.push_back(i);
    }
    bool result=std::binary_search(vec.begin(),vec.end(),6);
    if(result)
    {
        std::cout<<"element found"<<std::endl;
    }
    else
    {
        std::cout<<"Element did not found"<<std::endl;
    }
}