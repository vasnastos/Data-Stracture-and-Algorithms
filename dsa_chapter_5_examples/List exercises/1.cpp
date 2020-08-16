/*
Να κατασκευαστεί πρόγραμμα το οποίο μέσω λίστας θα πραγματοποιεί τις ακόλουθες λειτουργίες:
Το πρόγραμμα θα αποθηκεύει στοιχεία για φοιτητές{όνομα,εξάμηνο,επίδοση} και θα πραγματοποιεί 
  •Εισαγωγή ενός φοιτητή στο τέλος της λίστας(push_back).
  •Διαγραφή με βάση το id ενός φοιτητή στην λίστα.
  •Αναζήτηση με βάση το id ενός φοιτητή στην λίστα.
  •Εύρεση του αριθμού επιτυχοντων και αποτυχόντων στο μάθημα.
  •Εκτύπωση της λίστας.
Στην κύρια συνάρτηση να εισάγωνται τυχαία στην λίστα 10 εγγραφές και να κληθούν από μία φορά οι παραπάνω
συναρτήσεις.
*/

#include <iostream>
#include <random>
#include <string>
struct student
{
    std::string id;
    int semester;
    double grade;
    student *next;
};

class list
{
    std::string lesson;
    student *head;
    public:
      list():lesson(""),head(nullptr) {}
      list(std::string ln):lesson(ln),head(nullptr) {}
      list(std::string ln,std::string id,int sem,double gr):lesson(ln)
      {
          this->head=new student{id,sem,gr,nullptr};
      }
      void push_back(student &s)
      {
          if(this->head==nullptr)
          {
              this->head=new student{s.id,s.semester,s.grade,nullptr};
              return;
          }
          student *curr=this->head;
          while(curr->next!=nullptr)
          {
              curr=curr->next;
          }
          student *newst=new student{s.id,s.semester,s.grade,nullptr};
          curr->next=newst;
          newst->next=nullptr;
      }
      void erase(std::string id)
      {
          student *searchnode=this->head;
          student *prev=searchnode;
          int i=1;
          while(searchnode!=nullptr)
          {
              if(searchnode->id==id)
              {
                  break;
              }
              i++;
              prev=searchnode;
              searchnode=searchnode->next;
          }
          if(i==1)
          {
              student *temp=this->head;
              this->head=this->head->next;
              delete temp;
          }
          if(searchnode==nullptr)
          {
              std::cout<<"Student did not found"<<std::endl;
              return;
          }
          student *s=prev->next;
          prev->next=prev->next->next;
          delete s;
      }
      void search_student(std::string id)
      {
          student *search=this->head;
          while(search!=nullptr)
          {
              if(search->id==id)
              {
                  std::cout<<"ID:"<<search->id<<"\t"<<"Grade"<<search->grade<<std::endl;
                  
              }
              search=search->next;
          }
      }
      void pass()
      {
          int count=0;
          student *s=this->head;
          while(s!=nullptr)
          {
              if(s->grade>=5.0)
              {
                  count++;
              }
              s=s->next;
          }
          std::cout<<count<<" students pass lesson:"<<this->lesson<<std::endl;
      }
      void fail()
      {
         int count=0;
          student *s=this->head;
          while(s!=nullptr)
          {
              if(s->grade<5.0)
              {
                  count++;
              }
              s=s->next;
          }
          std::cout<<count<<" students fail lesson:"<<this->lesson<<std::endl;
      }
      void printlist()
      {
          std::cout<<"Lesson "<<this->lesson<<" stats"<<std::endl;
          student *s=this->head;
          while(s!=nullptr)
          {
              std::cout<<"STUDENT:"<<s->id<<"\t"<<s->semester<<"\t"<<s->grade<<std::endl;
              s=s->next;
          }
      }
};

int main()
{
    list les("Programming");
    std::mt19937 mt(RAND_MAX);
    std::string id;
    int semester;
    double grade; 
    std::uniform_int_distribution <int> charval(0,26);
    std::uniform_int_distribution <int> digit(0,9);
    std::uniform_int_distribution <int> dist(0,16);
    std::uniform_real_distribution <double> gr(0.0,10.0);
    for(int i=0;i<10;i++)
    {
        id="";
        for(int j=0;j<5;j++)
        {
            if(j<3)
            id+='a'+charval(mt);
            else
            {
                id+=std::to_string(digit(mt));
            }
            
        }
        semester=dist(mt);
        grade=gr(mt);
        student s{id,semester,grade,nullptr};
        les.push_back(s);
    }
    les.printlist();

    //SHOW PASS--FAIL
    std::cout<<"Lesson ratio:::"<<std::endl;
    les.pass();
    les.fail();

   //SEARCH BY ID
   std::cout<<"Give search id:";
   std::cin>>id;
   les.search_student(id);

   //ERASE BY ID
   std::cout<<"Give id you want to erase:";
   std::cin>>id;
   les.erase(id);

   //SHOW FULL INFO
   les.printlist();
}