#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <utility>
#define TOP 3

class employee
{
    private:
      std::string name;
      double salary;
    public:
      employee(std::string n="",double s=0.0):name(n),salary(s) {}
      double get_salary() {return this->salary;}
      std::string get_name() {return this->name;}
      bool operator<(const employee &emp)const {return this->salary<emp.salary;}
      bool operator>(const employee &emp)const {return this->salary>emp.salary;}
      employee &operator=(const employee &e)
      {
          this->name=e.name;
          this->salary=e.salary;
          return *this;
      }
      friend std::ostream &operator<<(std::ostream &os,const employee &e)
      {
          os<<e.name<<"----"<<e.salary;
          return os;
      }
};

int main()
{
    std::mt19937 mt(1892);
    std::uniform_real_distribution <double> sal(0,1900);
    std::priority_queue <employee> pq;
    double highemp=-1.0;
    employee emp;
    for(int i=1;i<=10;i++)
    {
        employee e1("employee_"+std::to_string(i),sal(mt));
        pq.push(e1);
        if(highemp<e1.get_salary() || highemp==-1.0)
        {
            highemp=e1.get_salary();
            emp=e1;
        }
        std::cout<<"New Addition[Name:"<<e1.get_name()<<"  Salary:"<<e1.get_salary()<<"]======>";
        std::cout<<"Highest Paid Employee["<<emp.get_name()<<"--"<<emp.get_salary()<<"]"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout<<"Highest paid Employee:Name==>"<<emp.get_name()<<"\t"<<"Salary==>"<<emp.get_salary()<<std::endl;
    std::cout<<TOP<<" Employees with the highest payments"<<std::endl;
    std::vector <employee> e1;
    for(int i=0;i<TOP;i++)
    {
        e1.push_back(pq.top());
        std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    for(auto itr=e1.begin();itr!=e1.end();itr++)
    {
        pq.push(*itr);
    }
    std::cout<<"Queue size:"<<pq.size()<<std::endl;
    return 0;
}