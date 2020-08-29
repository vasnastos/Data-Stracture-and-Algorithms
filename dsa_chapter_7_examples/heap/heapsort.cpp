#include <iostream>
#include <random>
#include <sstream>

int seed()
{
    std::string st=__TIME__;
    std::stringstream ss(st);
    std::string word;
    while(std::getline(ss,word,':'))
    {

    }
    return std::stoi(word);
}

template <class T>
class heap
{
    const int static heap_limit=10000;
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
          T v=heapb[k];
          bool f=false;
          while(!f && 2*k<hs)
          {
              int j=2*k;
              if(j<hs)
              {
                  if(heapb[j]<heapb[j+1])
                  {
                      j++;
                  }
                  if(v>=heapb[j])
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
          heapb[k]=v;
      }
      void pop()
      {
          std::swap(heapb[1],heapb[hs]);
          hs--;
          heapify(1);
      }
      void heapsort(int i)
      {
          int n=hs;
           // Find largest among root, left child and right child
      int largest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;

       if (left < n && heapb[left] > heapb[largest])
           largest = left;

       if (right < n && heapb[right] > heapb[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
       if (largest != i) {
        std::swap(heapb[i],heapb[largest]);
        heapify(largest);
        }
      }
      void print()
      {
          std::cout<<"[";
          for(int i=1;i<=hs;i++)
          {
              if(i==hs)
              std::cout<<heapb[i];
              else
              {
                  std::cout<<heapb[i]<<",";
              }
          }
          std::cout<<"]"<<std::endl;
      }
      T top() {return heapb[1];}
      bool empty() {return hs==0;}
};

int main()
{
    heap <int> h1;
    std::mt19937 mt(seed());
    std::uniform_int_distribution <int> dist(0,800);
    for(int i=0;i<12;i++)
    {
        h1.push(dist(mt));
    }
    h1.heapify(1);
    h1.print();
    std::cout<<"Top:"<<h1.top()<<std::endl;
    h1.heapsort(0);
    std::cout<<"After heapsort"<<std::endl;
    h1.print();
}