/*
  Να κατασκευαστεί πρόγραμμα το οποίο θα διαβάζεί από δύο αρχεία ακέραιους και δεκαδικούς αριθμούς και θα του
  τοποθετεί στους κατάλληλους σωρούς.
  Οι σωροί θα πρέπει να υλοποιούν τις παρακάτω λειτουργίες¨
    •push()-->Εισαγωγή στοιχείου στον σωρό.
    •pop()-->Εξαγωγή στοιχείου από τον σωρό.
    •empty()-->Έλεγχος αν ο σωρός είναι άδειος.
    •top()-->Επιστροφη του στοιχείου στην κορυφή του σωρού.
    •print()-->συνάρτηση εκτύπωσης του σωρού.
    O Σωρός που θα υλοποιηθεί θα είναι σωρός ελαχίστων(Το μικρότερο στοιχείο θα είναι στην κορυφή).
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


template <class T>
class heap
{
    const int static heap_limit=100000;
    int hs=0;
    T heapb[heap_limit+1];
    public:
      heap() {}
      ~heap() {}
      void push(T elem)
      {
          hs++;
          heapb[hs]=elem;
          int pos=hs;
          while(pos!=1 && heapb[pos]<heapb[pos/2])
          {
              std::swap(heapb[pos],heapb[pos/2]);
              pos/=2;
          }
      }
      void heapify(int k)
      {
          T value=heapb[k];
          bool f=false;
          while(!f && 2*k<hs)
          {
              int j=2*k;
              if(j<hs)
              {
                  if(heapb[j]>heapb[j+1])
                  {
                      j++;
                  }
                  if(value<=heapb[j])
                  {
                      f=true;
                  }
                  else
                  {
                      heapb[k]=heapb[j];
                      k=j;
                  }
                  
              }
          }
          heapb[k]=value;
      }
      void pop()
      {
          std::swap(heapb[1],heapb[hs]);
          hs--;
          heapify(1);
      }
      bool empty() {return hs==0;}
      T top() {return heapb[1];}
      void print()
      {
          std::cout<<"[";
          for(int i=1;i<=hs;i++)
          {
              if(i==hs)
              {
                  std::cout<<heapb[i];
              }
              else
              {
                 std::cout<<heapb[i]<<",";
              }
          }
          std::cout<<"]"<<std::endl;
      }
      void clear()
      {
          for(int i=1;i<hs;i++)
          {
              heapb[i]=0;
          }
          hs=0;
      }
};

void readintegers(std::vector <int> &vec)
{
    std::ifstream is;
    std::string line;
    is.open("integers.txt",std::ios::in);
    int number;
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        ss>>number;
        vec.push_back(number);
    }
    is.close();
}

void readfloats(std::vector <double> &vec)
{
    std::ifstream is;
    is.open("floats.txt",std::ios::in);
    std::string line;
    double number;
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        ss>>number;
        vec.push_back(number);
    }
    is.close();
}

int main()
{
    std::vector <int> intgs;
    std::vector <double> fls;
    readintegers(intgs);
    readfloats(fls);
    heap <int> h1;
    heap <double> h2;
    for(std::vector <int>::iterator itr=intgs.begin();itr!=intgs.end();itr++)
    {
        h1.push(*itr);
    }
    for(auto itr=fls.begin();itr!=fls.end();itr++)
    {
        h2.push(*itr);
    }
    h1.heapify(1);
    h2.heapify(1);
     std::cout<<"*************** Heap Of Integers#### *************"<<std::endl;
     h1.print();
     std::cout<<"Top Element:"<<h1.top()<<std::endl;
     h1.pop();
     std::cout<<"Top element after pop:"<<h1.top()<<std::endl;
     h1.print();
     std::cout<<"**************************************************"<<std::endl;
     std::cout<<std::endl;

     std::cout<<"*************** Heap Of Doubles#### *************"<<std::endl;
     h2.print();
     std::cout<<"Top Element:"<<h2.top()<<std::endl;
     h2.pop();
     std::cout<<"Top element after pop:"<<h2.top()<<std::endl;
     h2.print();
     std::cout<<"**************************************************"<<std::endl;
     std::cout<<std::endl;
}