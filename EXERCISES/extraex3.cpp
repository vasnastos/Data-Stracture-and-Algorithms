/*
Υλοποιήστε μια διπλά συνδεδεμένη λίστα (double_linked_list) που να υποστηρίζει τις ακόλουθες λειτουργίες:
 εισαγωγή στοιχείου στην αρχή (insert_front), εισαγωγή στοιχείου στο τέλος (insert_back), διαγραφή στοιχείου 
 βάσει αναγνωριστικού (erase), εμφάνιση στοιχείων λίστας από την αρχή προς το τέλος (print_forward), εμφάνιση 
 στοιχείων λίστας από το τέλος προς την αρχή (print_reverse). 
Στη συνέχεια:
Διαβάστε υποθετικά δεδομένα φοιτητών και φοιτητριών από το αρχείο κειμένου (students.txt) και τοποθετήστε τις 
εγγραφές σε μια διπλά συνδεδεμένη λίστα. Θεωρείστε ότι η γραμμογράφηση του αρχείου είναι η ακόλουθη: <κωδικός> 
<όνομα> <εξάμηνο> <κατεύθυνση> <βαθμός>. Εμφανίστε τη λίστα από την αρχή προς το τέλος.
Εισάγετε στην αρχή της λίστας την εγγραφή "011 iasonas 3 CS 7.0" και στο τέλος της λίστας εισάγετε την εγγραφή 
"012 electra 5 CE 6.0".
Διαγράψτε την εγγραφή με κωδικό 005. Εμφανίστε τη λίστα από την αρχή προς το τέλος.
Διατηρείστε στη λίστα μόνο τους φοιτητές και τις φοιτήτριες από την κατεύθυνση CS με βαθμό από 5 και πάνω. 
Εμφανίστε όλες τις εγγραφές της λίστας από το τέλος προς την αρχή.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct student
{
    std::string id;
    std::string name;
    int semester;
    std::string direc;
    double grade;
};

struct node
{
   student s;
   node *next;
   node *previous;
};

void print_node(student *s)
{
    std::cout<<s->id<<"-"<<s->name<<"-"<<s->semester<<"-"<<s->direc<<"-"<<s->grade<<std::endl;
}

void insert_front(student &s,node *&curr)
{
    node *n=new node{s,nullptr,nullptr};
    n->next=curr;
    curr=n;
}

void insert_back(student &s,node *&curr)
{
    node *n=new node{s,nullptr,nullptr};
    curr->next=n;
    n->previous=curr;
    curr=n;
}

void erase(node *curr,std::string id)
{
   while(curr->s.id!=id)
   {
       curr=curr->next;
   }
   if(curr==nullptr)
   {
       std::cerr<<"No such id found on the list"<<std::endl;
       return;
   }
   node *del=curr;
   curr->next->previous=curr->previous;
   curr->previous->next=curr->next;
   delete del;
}

void print_forward(node *curr)
{
   while(curr!=nullptr)
   {
       print_node(&curr->s);
       curr=curr->next;
   }
}

void print_backward(node *curr)
{
    while(curr!=nullptr)
    {
        print_node(&curr->s);
        curr=curr->previous;
    }
}

void erase_fail_cs(node *curr)
{
    node *first=curr;
   while(curr!=nullptr)
   {
       if(curr->s.grade<5)
       {
           erase(first,curr->s.id);
       }
       curr=curr->next;
   }
}

void delete_list(node *curr)
{
    while(curr!=nullptr)
    {
        node *del=curr;
        curr=curr->next;
        delete del;
    }
}

int main()
{
    node *head=nullptr;
    node *tail=nullptr;
    std::ifstream fin;
    std::string line,word;
    fin.open("students.txt",std::ios::in);
    int counter=0;
    while(std::getline(fin,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        counter++;
        std::stringstream ss(line);
        std::vector <std::string> data;
        while(std::getline(ss,word,'-'))
        {
           data.push_back(word);
        }
        if(data.size()!=5) continue;
        student s{data[0],data[1],std::stoi(data[2]),data[3],std::stod(data[4])};
        if(counter==1)
        {
            std::cout<<"In"<<std::endl;
            head=new node{s,nullptr};
            tail=head;
        }
        else
        {
            insert_back(s,tail);
        }
    }
    fin.close();
    student ns{"011","iasonas",3,"CS",7.0};
    insert_front(ns,head);
    std::cout<<"1ST CHECK"<<std::endl;
    print_forward(head);
    std::cout<<std::endl;
    student ns1{"012","electra",5,"CE",6.0};
    insert_back(ns1,tail);
    std::cout<<"2ND CHECK"<<std::endl;
    print_forward(head);
    std::cout<<std::endl;
    erase_fail_cs(head);
    std::cout<<"3RD CHECK"<<std::endl;
    print_backward(tail);
    std::cout<<"List Deleted"<<std::endl;
    delete_list(head);
    delete head;
    delete tail;
}