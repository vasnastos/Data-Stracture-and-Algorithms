#include "template_double_linked_list.cpp"
#include <string>


int main(int argc,char *argv[])
{
    double startnum=8.3;
    /*if(argc!=2)
    {
        startnum=23.4;
    }
    else
    {
      startnum=std::stod(argv[1]);
    }*/ 
    double_linked_list <double> mylist(startnum);
    std::cout<<"Push_back function"<<std::endl;
    for(double x=8.9;x<15.6;x+=0.4)
    {
        mylist.push_back(x);
    }
    mylist.printlist();
    std::cout<<std::endl;
    std::cout<<"Operator <<"<<std::endl;
    mylist<<4.56;
    mylist.printlist();
    std::cout<<"erase_front function"<<std::endl;
    mylist.erase_front();
    mylist.printlist();
    std::cout<<"popback functions"<<std::endl;
    mylist.popback();
    mylist.printlist();
    std::cout<<"Insert function"<<std::endl;
    mylist.insert(4,67.8);
    mylist.printlist();
    std::cout<<"Erase Function"<<std::endl;
    mylist.erase(3);
    mylist.printlist();
    std::cout<<"Front-Back Functions"<<std::endl;
    std::cout<<"Front:"<<mylist.front()<<"\t"<<"Back:"<<mylist.back();
}