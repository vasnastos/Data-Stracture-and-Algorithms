#include "stack.cpp"

int main()
{
    stack <int> customstack;
    for(int i=0;i<10;i++)
    {
        customstack.push(i);
    }
    std::cout<<"5 top elements"<<std::endl;
    for(int i=0;i<5;i++)
    {
        std::cout<<"Top:"<<customstack.top()<<std::endl;
        customstack.pop();
    }
    customstack.push(20);
    std::cout<<"New top:"<<customstack.top()<<std::endl;

     customstack.pop();
     customstack.pop();
    std::cout<<"Top after push 2 elements:"<<customstack.top()<<std::endl;
    stack <char> mystack;
    std::cout<<"Alphabet by stack"<<std::endl;
    for(char x='a';x<='z';x++)
    {
       mystack.push(x);
    }
    while(!mystack.is_empty())
    {
        char upper=mystack.top()-32;
        std::cout<<"     "<<mystack.top()<<"--"<<upper<<std::endl;
        mystack.pop();
    }
}