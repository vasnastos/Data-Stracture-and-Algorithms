/*
   ΑΣΚΗΣΗ:
      Γράψτε ένα πρόγραμμα που να δέχεται τιμές από το χρήστη και για κάθε τιμή που θα δίνει ο χρήστης να εμφανίζει όλες
      τις τιμές που έχουν εισαχθεί μέχρι εκείνο το σημείο ταξινομημένες σε φθίνουσα σειρά.
      To πρόγραμμα να δίνει τις εξής δυνατότητες:
        •Να μπορεί ο χρήστης να εισάγει ένα αρχείο αντι για τιμή.
        •Να μπορεί να επιλέξει να αποθηκεύσει τις τιμες που θα  εχουν αποθηκευτεί σε αρχείο. 
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

int choices()
{
    int ch;
    std::cout<<"1-Give number"<<std::endl;
    std::cout<<"2-Load file with numbers"<<std::endl;
    std::cout<<"3-Save data"<<std::endl;
    std::cout<<"4-Stop App"<<std::endl;
    std::cout<<"Give choice:";
    std::cin>>ch;
    return ch;
}

void sort_vect(std::vector <double> &nms)
{
    sort(nms.begin(),nms.end(),[](const double &a,const double &b) {return a>b;});
    std::cout<<"*** Numbers after sort ***"<<std::endl;
    for(auto &x:nms)
    {
        std::cout<<"*         "<<std::setprecision(4)<<x<<"           *"<<std::endl;
    }
    std::cout<<"**************************"<<std::endl;
}

void add_number(std::vector <double> &nms)
{
    double n;
    std::cout<<"Give float number:";
    std::cin>>n;
    nms.push_back(n);
}

void load(std::vector <double> &vec)
{
  std::ifstream is;
  std::string fn,line;
  std::cout<<"Give filename:";
  std::cin>>fn;
  is.open(fn,std::ios::in);
  if(!is.is_open())
  {
      std::cerr<<"File not found!!!!"<<std::endl;
      return;
  }
  while(std::getline(is,line))
  {
      if(line.size()==0) continue;
      if(line.at(0)=='#') continue;
      vec.push_back(std::stoi(line));
  }
  is.close();
}

void save(std::vector <double> &vec)
{
   std::ofstream out;
   std::string fn;
   std::cout<<"Give filename:";
   std::cin>>fn;
   fn+=".out";
   out.open(fn,std::ios::out);
   out<<"***** List Of Numbers ********"<<std::endl;
   for(int i=0;i<vec.size();i++)
   {
       out<<"•"<<vec[i]<<std::endl;
   }
   out.close();
}

int main()
{
    int choice;
    std::vector <double> numbers;
    while(true)
    {
       choice=choices();
       if(choice==1)
       {
           add_number(numbers);
           sort_vect(numbers);
       }
       else if(choice==2)
       {
           load(numbers);
           sort_vect(numbers);
       }
       else if(choice==3)
       {
           save(numbers);
       }
       else if(choice==4)
       {
           exit(EXIT_SUCCESS);
       }   
    }   
}