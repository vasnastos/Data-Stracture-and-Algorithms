#include <iostream>
#include <list>
#include <vector>
namespace vasnastos{
    void print()
    {
        std::cout<<"Code created by Nastos Vasileios"<<std::endl;
        std::cout<<"Test code for hashing"<<std::endl;
    }
};
struct record
{
    std::string key;
    std::string phone;
};

class hashval
{
    int size;
    std::list <record *> *recs;
    size_t hash(std::string k)
    {
        size_t h=0;
        int j=1;
        for(int i=0;i<k.length();i++)
        {
            h+=j*k.at(i);
            j*=2;
        }
        return h;
    }
    public:
      hashval(int sz)
      {
          this->size=sz;
          recs=new std::list<record *>[size];
      }
      ~hashval()
      {
          for(int i=0;i<size;i++)
          {
              for(record *rec:recs[i])
              {
                delete rec;
              }
          }
          delete[] recs;
      }
      std::vector <record *> get(std::string k)
      {
          std::vector <record *> results;
          size_t hashcode=hash(k)%size;
          if(recs[hashcode].empty())
          {
              return results;
          }
          for(record *rec:recs[hashcode])
          {
              if(rec->key==k)
              {
                  results.push_back(rec);
              }
          }
          return results;
      }
      void insert(record *arecord)
      {
          size_t hashcode=hash(arecord->key)%size;
          recs[hashcode].push_back(arecord);
      }
      void erase(std::string key)
      {
          size_t hashcode=hash(key)%size;
          auto itr=recs[hashcode].begin();
          for(record *rec:recs[hashcode])
          {
              if(rec->key==key)
              {
                  recs[hashcode].erase(itr);
                  std::cout<<key<<" erased"<<std::endl;
                  return;
              }
              itr++;
          }
          std::cout<<key<<" not found"<<std::endl;
      }
      void print()
      {
          for(int i=0;i<size;i++)
          {
            std::cout<<"****************** Chain "<<i+1<<" *************************"<<std::endl;
            for(record *rec:recs[i])
            {
              std::cout<<rec->key<<"-------"<<rec->phone<<std::endl;
            }
            std::cout<<"****************************************************"<<std::endl<<std::endl;
          }
      }
};

int main()
{
    std::cout<<"BlockChain SIMULATOR"<<std::endl;
    record *r1=new record{"11AM","1234567890"};
    record *r2=new record{"36BJ","2345678901"};
    record *r3=new record{"13AM","3456789012"};
    record *r4=new record{"31BJ","4567890123"};
    record *r5=new record{"34BJ","5678901234"};
    record *r6=new record{"13AM","6789012345"};
    record *r7=new record{"21KL","6123490876"};
    record *r8=new record{"16TY","5678123400"};
    hashval vt(2);
    vt.insert(r1);
    vt.insert(r2);
    vt.insert(r3);
    vt.insert(r4);
    vt.insert(r5);
    vt.insert(r6);
    vt.insert(r7);
    vt.insert(r8);
    vt.print();
    vt.erase("11AM");
    std::cout<<std::endl;
    vt.print();
    std::cout<<"SEARCH RESULTS FOR 13AM:"<<std::endl;
    for(record *r:vt.get("13AM"))
    std::cout<<r->phone<<std::endl;
    std::cout<<std::endl;
    vasnastos::print();
    return 0;
}