#include "file_data.cpp"
#include <thread>
int main()
{
    list <int> Listofintegers;
    list <double> Listoffloats;
    
    //INSERTS ELEMENTS TO LISTS
    read_data(Listofintegers,1);
    read_data(Listoffloats,2);
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //PUSH_FRONT
    std::cout<<"Pushfront results"<<std::endl;
    Listofintegers.push_front(6);
    Listoffloats.push_front(6.7);
    std::cout<<"List of Integers::"<<std::endl;
    Listofintegers.print_list();
    std::cout<<"List of Double::"<<std::endl;
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //POP_BACK
    std::cout<<"Popback function results"<<std::endl;
    Listofintegers.pop_back();
    Listoffloats.pop_back();
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    
    //ERASE_FRONT
    std::cout<<"Erase Front function results"<<std::endl;
    Listoffloats.erase_front();
    Listofintegers.erase_front();
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //LENGTH
    std::cout<<"Length functions results"<<std::endl;
    std::cout<<"List of Integers:"<<Listofintegers.length()<<std::endl;
    std::cout<<"List of Floats:"<<Listoffloats.length()<<std::endl;
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //INSERT
    std::cout<<"Insertion function"<<std::endl;
    Listofintegers.insert(3,12);
    Listoffloats.insert(4,12.34);
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //ERASE
    std::cout<<"Erase function"<<std::endl;
    Listofintegers.erase(4);
    Listoffloats.erase(4);
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //FRONT
    std::cout<<"Front function"<<std::endl;
    std::cout<<"List Of Integers:"<<Listofintegers.front()<<std::endl;
    std::cout<<"List of Floats:"<<Listoffloats.front()<<std::endl;
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //BACK
    std::cout<<"Back function"<<std::endl;
    std::cout<<"List Of Integers:"<<Listofintegers.back()<<std::endl;
    std::cout<<"List of Floats:"<<Listoffloats.back()<<std::endl;
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //REVERSE 
    std::cout<<"Reverse function"<<std::endl;
    Listofintegers.reverse();
    Listoffloats.reverse();
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //BUBBLESORT
    std::cout<<"BubbleSort function"<<std::endl;
    Listofintegers.bubblesort();
    Listoffloats.bubblesort();
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    //SELECTION SORT
    std::cout<<"Selection sort function"<<std::endl;
    Listofintegers.selection_sort();
    Listoffloats.selection_sort();
    Listofintegers.print_list();
    Listoffloats.print_list();
    std::cout<<std::endl;
    
}