/*
ΑΣΚΗΣΗ:
  Γράψτε ένα πρόγραμμα που να διαβάζει όλες τις λέξεις ενός αρχείου κειμένου και να εμφανίζει πόσες φορές υπάρχει
  η κάθε λέξη στο κείμενο σε αύξουσα σειρά συχνότητας. Χρησιμοποιήστε ως είσοδο το κείμενο του βιβλίου 1984 του
  George Orwell (http://gutenberg.net.au/ebooks01/0100021.txt).
*/

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <utility>

void insert(std::map <std::string,int> &wrds,std::string w)
{
    bool found=false;
    for(auto &nw:wrds)
    {
        if(w==nw.first)
        {
            wrds[w]++;
            found=true;
        }
    }
    if(!found)
    {
        wrds[w]=1;
    }
}

void read_data(std::map <std::string,int> &wrds)
{
   std::ifstream is;
   std::string line,word;
   is.open("gutenberg.txt",std::ios::in);
   while(std::getline(is,line))
   {
       if(line.size()==0) continue;
       std::stringstream ss(line);
       ss>>word;
       do
       {
           if((word[0]<'A' && word[0]>'Z') && word[0]<'a' && word[0]>'z')
           word.erase(word.begin(),word.begin());
       } while ((word[0]<'A' && word[0]>'Z') && (word[0]<='a' && word[0]>'z'));
       do
       {
           if((word[word.size()-1]<'A' && word[word.size()-1]>'Z') && (word[word.size()-1]<'a' && word[word.size()-1]>'z'))
           word.erase(word.size()-1,word.size());
       } while ((word[word.size()-1]<'A' && word[word.size()-1]>'Z') && (word[word.size()-1]<'a' && word[word.size()-1]>'z'));
       insert(wrds,word);    
   }
   is.close();
}

void save_info(std::map <std::string,int> &wrds)
{
    std::ofstream out;
    std::string fn;
    std::cout<<"Give filename:";
    std::cin>>fn;
    out.open(fn,std::ios::out);
    out<<"WORD--------RATIO"<<std::endl;
    for(auto &w:wrds)
    {
       out<<w.first<<"     "<<w.second<<std::endl; 
    }   
    out.close();
}
int main(int argc,char **argv)
{
   std::map <std::string,int> words;
   read_data(words);
   save_info(words);
   exit(EXIT_SUCCESS);
}