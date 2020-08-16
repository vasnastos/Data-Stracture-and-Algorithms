/*
Η ταξινόμηση με εισαγωγή (insertion­sort) λειτουργεί δημιουργώντας μια ταξινομημένη λίστα στο αριστερό άκρο των δεδομένων και επαναληπτικά
 τοποθετεί το στοιχείο το οποίο βρίσκεται δεξιά της ταξινομημένης λίστας στη σωστή θέση σε σχέση με τα ήδη ταξινομημένα στοιχεία
*/
#include <iostream>
template <class T>void insertion_sort(T *b,int n)
{
    for(int i=0;i<n;i++)
    {
        T keyvalue=b[i];
        int j=i-1;
        while(j>=0 && b[j]>keyvalue)
        {
           T key=b[j];
           b[j]=b[j+1];
           b[j+1]=key;
           j--;
        }
        b[j+1]=keyvalue;
    }
}

int main()
{
    int a[]{4,2,15,11,10,8,9};
    double k[]{6.5,3.1,4.8,11.9,1.78,3.15};
    std::cout<<"    Insertion sort for integers   "<<std::endl;
    insertion_sort(a,sizeof(a)/sizeof(a[0]));
    insertion_sort(k,sizeof(k)/sizeof(k[0]));
    for(auto itr=a;itr!=a+(sizeof(a)/sizeof(a[0]));itr++)
    {
        std::cout<<"a["<<itr-a<<"]:"<<*itr<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"    Insertion sort for Doubles     "<<std::endl;
    for(auto itr=k;itr!=k+(sizeof(k)/sizeof(k[0]));itr++)
    {
        std::cout<<"k["<<itr-k<<"]:"<<*itr<<std::endl;
    }
    return 0;
}