/*
Γράψτε ένα πρόγραμμα που για ένα λεκτικό που θα δέχεται ως είσοδο, να επιστρέφει το χαρακτήρα (γράμματα κεφαλαία,
γράμματα πεζά, ψηφία, σύμβολα) που εμφανίζεται περισσότερες φορές καθώς και πόσες φορές εμφανίζεται στο λεκτικό
*/
#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <map>

char max_show(std::string &key)
{
    std::set <char> characters;
    for(int i=0;i<key.length();i++)
    {
       characters.insert(key.at(i));
    }
    std::map <char,int> chars;
    for(std::set <char>::iterator itr=characters.begin();itr!=characters.end();itr++)
    {
        chars[*itr]=0;
    }
    for(std::set<char>::iterator itr=characters.begin();itr!=characters.end();itr++)
    {
        for(int i=0;i<key.length();i++)
        {
            if(key.at(i)==*itr)
            {
                chars[*itr]++;
            }
        }
    }
    chars.erase(chars.find('_'));
    //Διαγραφή του διαχωριστικού χαρακτήρα κάτω παύλας.
    std::map <char,int>::iterator itr=chars.begin();
    char max=itr->first;
    int maxlength=itr->second;
    itr++;
    for(auto sitr=itr;sitr!=chars.end();sitr++)
    {
        if(sitr->second>maxlength)
        {
            max=sitr->first;
            maxlength=sitr->second;
        }
    }
    return max;
}

int main(int argc,char *argv[])
{
    std::string text="This program_equips_you_with_knowledge_of_algorithms,performance,hardware,and_design_and_documentation_methods.You_will_be_able_to_apply_this_to_create_reliable_protocols_for_the_behavior_of_complex_software_systems.";
    std::cout<<"Character with the most appereances on the string:"<<max_show(text)<<std::endl;
    std::ifstream is;
    std::string line;
    text="";
    is.open("textsample.txt");
    while(std::getline(is,line))
    {
        for(int i=0;i<line.length();i++)
        {
            if(line.at(i)==' ')
            {
                line[i]='_';
            }
        }
       text+=line;
    }
    is.close();
    std::cout<<"Character with the most appereances on the file retrived string:"<<max_show(text)<<std::endl;
    return 0;   
}