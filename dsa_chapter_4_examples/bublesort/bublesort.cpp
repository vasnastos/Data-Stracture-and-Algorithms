#include <iostream>
template <class T>void bubblesort(T *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                T temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int a[]{6,3,2,1,56,21};
    double b[]{1.2,4.5,7.8,21.3,9.1,7.21};
    bubblesort(a,sizeof(a)/sizeof(a[0]));
    bubblesort(b,sizeof(b)/sizeof(b[0]));
    std::cout<<"  Integers BubbleSort "<<std::endl;
    for(auto itr=a;itr!=a+sizeof(a)/sizeof(a[0]);itr++)
    {
        std::cout<<"a["<<itr-a<<"]:"<<*itr<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"  Double BubbleSort "<<std::endl;
    for(auto itr=b;itr!=b+sizeof(b)/sizeof(b[0]);itr++)
    {
        std::cout<<"b["<<itr-b<<"]:"<<*itr<<std::endl;
    }
}