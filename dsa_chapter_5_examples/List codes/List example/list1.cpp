/*
Η συνδεδεμένη γραμμική λίστα αποτελείται από μηδέν ή περισσότερους κόμβους. Κάθε κόμβος περιέχει δεδομένα και
έναν ή περισσότερους δείκτες σε άλλους κόμβους της συνδεδεμένης λίστας. Συχνά χρησιμοποιείται ένας πρόσθετος κόμβος
με όνομα head (κόμβος κεφαλής) που δείχνει στο πρώτο στοιχείο της λίστας και μπορεί να περιέχει επιπλέον πληροφορίες
όπως το μήκος της.

Ένα πρώτο παράδειγμα που παρουσιάζεται στον παρακάτω κώδικα είναι μίας απλά συνδεδεμένης λίστας ακεραίων 
η οποία θα υλοποιεί τις ακόλουθες συναρτήσεις:
 •push_back()-->προσθήκη στοιχείου στην  τελευταία θέση της λίστας.
 •push_front()-->προσθήκη στοιχείου στην πρώτη θέση της λίστας.
 •insert(int i)-->τοποθέτηση στοιχείου στην θέση i (πραγματική θέση).
 •sum()-->άθροισμα της λίστας. 
 •length()-->μέγεθος της λίστας.
 •print_list()-->Εκτύπωση της λίστας
 •Για την υλοποίηση της λίστας θα χρησιμοποιηθεί μία custom δομή node με δεδομένα μία ακέραια μεταβλητή data
 που θα αποτελεί το περιεχόμενου του κόμβου καθώς και ένα δείκτη τύπου node next που θα δείχνει στον επόμενο
 κόμβο.
 •Τα default δεδομένα θα φορτώνονται στην λίστα από ένα αρχείο. 
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <vector>

//Υλοποίηση κόμβου
struct node 
{
    int data;
    node *next;
};

void push_back(node *curr,int d)
{
    while(curr->next!=nullptr)
    {
       curr=curr->next;
    }
    node *newnode=new node{d,nullptr};
    curr->next=newnode;
}

void push_front(node *&curr,int d)
{
   node *newnode=new node{d,nullptr};
   newnode->next=curr;
   curr=newnode;
}

void insert(node *curr,int i,int data)
{
    node *newnode=new node{data,nullptr};
    for(int j=1;j<i-1;j++)
    {
        curr=curr->next;
    }
    node *temp=curr->next;
    curr->next=newnode;
    newnode->next=temp;
}

int sum(node *curr)
{
    int s=0;
    while(curr!=nullptr)
    {
        s+=curr->data;
        curr=curr->next;
    }
    return s;
}

int length(node *curr)
{
    int len=0;
    while(curr!=nullptr)
    {
        len++;
        curr=curr->next;
    }
    return len;
}

void print_list(node *curr)
{
    std::cout<<"List::";
    int i=0;
    int j=length(curr)-1;
    while(curr!=nullptr)
    {
        if(i<j)
        {
            std::cout<<curr->data<<"->";
        }
        else
        {
            std::cout<<curr->data;
        }
        i++;
        curr=curr->next;
    }
    std::cout<<std::endl;
}

void read_data(std::vector <int> &elem)
{
    std::ifstream is;
    std::string line;
    is.open("numbers.txt");
    int number;
    if(!is.is_open()) return;
    while(std::getline(is,line))
    {
       std::stringstream ss(line);
       ss>>number;
       elem.push_back(number);
    }
    is.close();
}