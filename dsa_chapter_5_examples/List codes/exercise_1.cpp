/*
  Nα κατασκευαστεί λίστα που θα αποθηκεύει τηλέφωνα(Ονομα,διεύθυνση,τηλέφωνο) και θα υλοποιεί τις παρακάτω επιλογές:
    •Εισαγωγή εγγραφής στο τέλος της λίστας.
    •Διαγραφή στοιχείου από το τέλος της λίστας.
    •Αναζήτηση στοιχείου με βάση τον τηλεφωνικό αριθμό.
    •Εκτύπωση λίστας.
    Στην κύρια συνάρτηση να εισάγωνται οι παρακάτω εγγραφές
      name_1,address_1,1234567890
      name_2,address_2,2345678901
      name_3,address_3,3456789012
      name_4,address_4,4567890123
    Επίσης να διαγραφεί η τελευταία εγγραφή από την λίστα,
    να γίνει αναζήτηση του τηλεφώνου 3456789012
    και τέλος να εμφανιστούν όλες οι εγγραφές τις λίστας.
*/
#include <iostream>

using namespace std;

//Υλοποίηση κόμβου για αναπαράσταση τηλεφώνων.
struct phone
{
    string name;
    string address;
    string phonenumber;
    phone *next;
};

//Εισαγωγή στοιχείου στο τέλος της λίστας
void push_back(phone *curr,string n,string add,string p)
{
   phone *newphone=new phone{n,add,p,nullptr};
   //(phone *)malloc(sizeof(phone))
   while(curr->next!=nullptr)
   {
       curr=curr->next;
   }
   curr->next=newphone;
}

//Διαγραφή στοιχείου από το τέλος της λίστας.
void pop_back(phone *curr)
{
    phone *temp;
    while(curr->next!=nullptr)
    {
        temp=curr;
        curr=curr->next;
    }
    temp->next=nullptr;
    //free(curr)
    delete curr;
}

//Αναζήτηση στοιχείου με βάση τον τηλεφωνικό αριθμό.
void search(phone *cr,string ph)
{
    while(cr!=nullptr)
    {
        if(cr->phonenumber==ph)
        {
            cout<<"Name:"<<cr->name<<"\tAddress:"<<cr->address<<endl;
            return;
        }
        cr=cr->next;//!!!!!!Προχαράω στον επόμενο κόμβο.
    }
}

//Εκτύπωση της λίστας
void printlist(phone *curr)
{
    while(curr!=nullptr)
    {
        cout<<curr->name<<"   "<<curr->address<<"   "<<curr->phonenumber<<endl;
        curr=curr->next;
    }
}

//Διαγραφή των κόμβων της λίστας.
void deletelist(phone *p)
{
    phone *temp;
    while(p!=nullptr)
    {
        temp=p;
        p=p->next;
        delete temp;
    }
}

int main()
{
    //Αρχικός κόμβος της λίστας
   phone *p1=new phone{"name_1","address_1","1234567890",nullptr};
   push_back(p1,"name_2","address_2","2345678901");
   push_back(p1,"name_3","address_3","3456789012");
   push_back(p1,"name_4","address_4","4567890123");
   pop_back(p1);
   search(p1,"3456789012");
   printlist(p1);
   deletelist(p1);
}