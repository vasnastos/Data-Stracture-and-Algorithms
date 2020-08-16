#include "queue.cpp"
#include <thread>

int main()
{
    queue <int> myqueue;
    queue <char> myqueue1;
    for(int i=1;i<10;i++)
    {
        std::cout<<"Elements pushed::"<<std::endl;
        std::cout<<"myqueue:"<<i<<std::endl;
        char p='A'+i;
        std::cout<<"myqueue1:"<<p<<std::endl;
        std::cout<<std::endl;
        myqueue.push(i);
        myqueue1.push('A'+i);
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }
    std::cout<<"Front elements"<<std::endl;
    std::cout<<"myqueue:"<<myqueue.front()<<std::endl;;
    std::cout<<"myqueue1:"<<myqueue1.front()<<std::endl;
    std::cout<<"Back Elements"<<std::endl;
    std::cout<<"myqueue:"<<myqueue.back()<<std::endl;
    std::cout<<"myqueue1:"<<myqueue1.back()<<std::endl;
    std::cout<<"Pop five elements"<<std::endl;
    for(int i=0;i<5;i++)
    {
        std::cout<<myqueue.top()<<" popped"<<std::endl;
        std::cout<<myqueue1.top()<<" popped"<<std::endl;
        myqueue.pop();
        myqueue1.pop();
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }

    std::cout<<"Queues sizes"<<std::endl;
    std::cout<<"myqueue:"<<myqueue.size()<<std::endl;
    std::cout<<"myqueue1:"<<myqueue1.size()<<std::endl;
    std::cout<<"Queues front and back elements"<<std::endl;
    std::cout<<"myqueue:"<<"Front:"<<myqueue.front()<<"\tBack:"<<myqueue.back()<<std::endl;
    std::cout<<"myqueue1:"<<"Front:"<<myqueue1.front()<<"\tBack:"<<myqueue1.back()<<std::endl;
}