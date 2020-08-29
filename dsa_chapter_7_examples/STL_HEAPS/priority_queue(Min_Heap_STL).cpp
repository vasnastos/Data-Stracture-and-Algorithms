/*
Να κατασκευαστεί σωρός ελαχίστων με μαθητές όπου θα εισάγωνται 10 μαθητές με τυχαία στοιχεία και
θα εμφανίζονται οι τρεις μαθητές με τους βαθμούς.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <random>
#define TOP 3

class student
{
    private:
      std::string id;
      double grade;
    public:
      student(std::string n="",double g=0.0):id(n),grade(g) {}
      std::string get_id()const {return this->id;}
      double get_grade()const {return this->grade;}
      bool operator>(const student &e1)const {return this->grade>e1.grade;}
      friend std::ostream &operator<<(std::ostream &os,const student &s)
      {
          os<<s.id<<"----"<<s.grade;
          return os;
      }
};

class myComparator
{
    public:
      bool operator()(const student &e1,const student &e2)
      {
          return e1>e2;
      }
};

int main()
{
    std::mt19937 mt(1234);
    std::uniform_real_distribution <double> gr(0.1,10.0);
    std::cout.precision(4);
    std::priority_queue <student,std::vector <student>,myComparator> pq;
    student lst;
    for(int i=1;i<=10;i++)
    {
        student s("student_"+std::to_string(i),gr(mt));
        pq.push(s);
        if(lst.get_grade()!=pq.top().get_grade())
        lst=s;
        std::cout<<"New Addition["<<s<<"]====>"<<"Less Grade of student:"<<lst<<std::endl;
    }
    std::cout<<"Top 3 students"<<std::endl;
    std::vector <student> sts;
    for(int i=0;i<TOP;i++)
    {
       std::cout<<pq.top()<<std::endl;
       sts.push_back(pq.top());
       pq.pop();
    }
    for(auto itr=sts.begin();itr!=sts.end();itr++)
    {
        pq.push(*itr);
    }
    std::cout<<"Total elements in heap:"<<pq.size()<<std::endl;
    return 0; 
}