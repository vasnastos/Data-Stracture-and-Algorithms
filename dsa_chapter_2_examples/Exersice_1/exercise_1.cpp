/*
ΑΣΚΗΣΗ:Να γραφεί συνάρτηση η οποία θα δέχεται σαν όρισμα ένα μονοδιάστατο πίνακα  το μέγιστο και το ελάχιστο στοιχείο του πίνακα.
Να κληθεί η συνάρτηση για έναν  πίνακα ακεραίων και για έναν πίνακα students.(όνομα και βαθμός μαθητή).
[Θα βρίσκει τον μαθητή με τον μέγιστο και τον ελάχιστο βαθμό].
EXTRA ΕΡΩΤΗΜΑΤΑ:
      Α)Η συνάρτηση να υπολογίζει πόσες φορές βρέθηκε το μέγιστο στοιχείο στον πίνακα. 
      Β)Να αποθηκευτούν τα αποτελέσματα των συναρτήσεων σε αρχείο results.out.   
*/ 

#include <iostream>
#include <fstream>

struct student
{
    std::string name;
    double grade;
    bool operator>(const student &s1)const {return grade>s1.grade;}
    //bool operator<(const student &s1)const {return grade<s1.grade;}
    bool operator==(const student &s1)const {return this->grade==s1.grade;}
};

/*
Υπερφόρτωση τελεστή > για δεδομένα τύπου student.
bool operator>(const student &s1,const student &s2)
{
    if(s1.grade>s2.grade)
    {
        return true;
    }
    else
    {
        return false;
    }
   return s1.grade>s2.grade;
}
*/

//Υπερφόρτωση τελεστή < για δεδομένα τύπου student.
bool operator<(const student &s1,const student &s2)
{
    return s1.grade<s2.grade;
}

//Η συνάρτηση δεν θα μπορέσει να συγκρίνει 2 μεταβλητές τύπου student γιατί οι τελεστές σύγκρισης δεν λειτουργουν για custom τύπους(class/structs).
//Yπερφόρτωση τελεστή(operator)
template <class T> void find_values(T *board,int size,T &max,T &min,int *cnt)
{
    max=min=board[0];
    for(int i=1;i<size;i++)
    {
       if(board[i]>max) max=board[i];
       if(board[i]<min) min=board[i];
    }
    //A)
    (*cnt)=0;
    for(int i=0;i<size;i++)
    {
        if(board[i]==max)
        {
            (*cnt)++;
        }
    }
}

int main()
{
    int board[8]={6,23,17,8,15,23,5,23};
    student students[8]={{"petros",7.8},{"nikos",2.1},{"giorgos",8.9},{"Dimitris",9.1},{"Maria",3.5},{"vasilis",9.1},{"Kostas",9.1},{"Ilias",0.6}};
    int max_integer,min_integer;
    int count_max_int;
    student max_student,min_student;
    int cnt_student_max;
    find_values(board,5,max_integer,min_integer,&count_max_int);
    std::cout<<"********* Integer Board *********"<<std::endl;
    std::cout<<"Max integer:"<<max_integer<<std::endl;
    std::cout<<"Min integer:"<<min_integer<<std::endl;
    std::cout<<"Count max:"<<count_max_int<<std::endl;
    std::cout<<"**********************************"<<std::endl;
    find_values(students,5,max_student,min_student,&cnt_student_max);
    std::cout<<"********* Student Board ***********"<<std::endl;
    std::cout<<"Best::Student Name:"<<max_student.name<<"\t"<<"Student Grade:"<<max_student.grade<<std::endl;
    std::cout<<"Worst::Student Name:"<<min_student.name<<"\t"<<"Student Grade:"<<min_student.grade<<std::endl;
    std::cout<<"Max exists:"<<cnt_student_max<<std::endl;
    std::cout<<"************************************"<<std::endl;
    return 0;
    //B)
    std::ofstream out;
    out.open("results.out",std::ios::out);
    out<<std::endl;
    out<<"       RESULTS OF PROGRAM              "<<std::endl;
    out<<"********* Integer Board *********"<<std::endl;
    out<<"Max integer:"<<max_integer<<std::endl;
    out<<"Min integer:"<<min_integer<<std::endl;
    out<<"Count max:"<<count_max_int<<std::endl;
    out<<"**********************************"<<std::endl;
    out<<std::endl;
    out<<"********* Student Board ***********"<<std::endl;
    out<<"Best::Student Name:"<<max_student.name<<"   "<<"Student Grade:"<<max_student.grade<<std::endl;
    out<<"Worst::Student Name:"<<min_student.name<<"  "<<"Student Grade:"<<min_student.grade<<std::endl;
    out<<"Max exists:"<<cnt_student_max<<std::endl;
    out<<"************************************"<<std::endl;
    out<<std::endl;
}