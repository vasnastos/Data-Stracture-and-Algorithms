#include "list2.cpp"
int main()
{
    std::vector <int> data;
    read_data(data);
    //push the elements to the list.
    node *head=new node{data.at(0),nullptr};
    for(int i=1;i<data.size();i++)
    {
        push_back(head,data.at(i));
        print_list(head);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    int calc,pos;
    //Εισαγωγή στοιχείου στην λίστα.
    std::cout<<"Give element you want to insert into your list:";
    std::cin>>calc;
    std::cout<<"Give position you want to add this element:";
    std::cin>>pos;
    if(length(head)<pos)
    {
        std::cerr<<"Invalid selected position,you can't insert element to this position"<<std::endl;
    }
    else
    {
       insert(head,pos,calc);
       print_list(head);
    }

    //Εισαγωγή στοιχείου στην πρώτη θέση της λίστας.
    std::cout<<"Give element you want to add in the front of the list:";
    std::cin>>calc;
    push_front(head,calc);
    print_list(head);

    //erase front
    std::cout<<"Erase front element of the list"<<std::endl;
    erase_front(head);
    print_list(head);
    //erase from position
    int pos;
    std::cout<<"Give position you want to erase:";
    std::cin>>pos;
    if(pos>=length(head))
    {
        std::cerr<<"Invalid position you can't erase from this position"<<std::endl;
    }
    else
    {
        std::cout<<"Erase position "<<pos<<std::endl;
        erase(head,pos);
    }
    print_list(head);

    //Διαγραφή τελευταίου κόμβου της λίστας
     std::cout<<"Popback an element"<<std::endl;
     pop_back(head);
     print_list(head);

    //Ταξινόμιση με χρήση του αλγορίθμου selection sort
    std::cout<<"Sort list using selction sort algorithm!!!"<<std::endl;
    selection_sort(head);
    print_list(head);
}