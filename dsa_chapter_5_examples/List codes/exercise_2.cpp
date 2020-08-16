/*
  Να κατασκευαστεί λίστα που θα αποθηκεύει δεκαδικούς αριθμούς και θα υλοποιποιεί τις ακόλουθες λειτουργίες
    •Εισαγωγή στοιχείου στην αρχή της λίστας.
    •Εισαγωγή στοιχείου στο τέλος της λίστας.
    •Υπολογισμος μέσου όρου λίστας.
    •Υπολογισμός θέσης ελαχίστου λίστας.
    •Εκτύπωση λίστας.
    Στην κύρια συνάρτηση το πρόγραμμα θα εισάγει στην λίστα αριθμούς από αρχείο numbers.txt και επίσης θα γίνεται εισαγωγή
    στην αρχή της λίστας ενός αριθμoύ που θα δίνει ο χρήστης.
    Τέλος θα εμφανίζονται τα στοιχεία της λίστας καθώς και ο μέσος όρος της λίστας και η θέση ελαχίστου στοιχείου της λίστας.
*/
#include <iostream>
#include <fstream>
#include <sstream>

struct node
{
   double num;
   node *next;
};

using namespace std;

void push_back(node *curr,double n)
{
    node *newnode=new node{n,nullptr};
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=newnode;
}

void push_front(node *&curr,double n)
{
    node *newnode=new node{n,nullptr};
    newnode->next=curr;
    curr=newnode;
}

double average(node *curr)
{
    double avg=0.0;
    int i=0;
    while(curr!=nullptr)
    {
        i++;
        avg+=curr->num;
        curr=curr->next;
    }
    return avg/i;
}

int min_position(node *curr)
{
    double min=curr->num;
    int i=1;
    int minpos=1;
    while(curr!=nullptr)
    {
        if(curr->num<min)
        {
            min=curr->num;
            minpos=i;
        }
        curr=curr->next;
        i++;
    }
    return minpos;
}

void printlist(node *curr)
{
    while(curr!=nullptr)
    {
        cout<<"Num:"<<curr->num<<endl;
        curr=curr->next;
    }
}

int main()
{
    node *head=nullptr;
   ifstream is;
   string line;
   double n;
   int counter=0;
   is.open("numbers.txt");
   while(getline(is,line))
   {
       counter++;
      stringstream ss(line);
      ss>>n;
      if(counter==1)
      {
          head=new node{n,nullptr};
      }
      else
      {
          push_back(head,n);
      } 
   }
   is.close();
   cout<<"List after file insertion"<<endl;
   printlist(head);
   cout<<endl;
   double number;
   cout<<"Give number:";
   cin>>number;
   push_front(head,number);
   cout<<"************* Summary info of list ****************"<<endl;
   cout<<"         List numbers"<<endl;
   printlist(head);
   cout<<"Average="<<average(head)<<endl;
   cout<<"Position of min list element:"<<min_position(head)<<endl;
   cout<<"***************************************************";
}