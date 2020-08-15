/*
Γράψτε κώδικα που να δημιουργεί μια δομή με όνομα student (σπουδαστής) και να έχει ως πεδία το name (όνομα) τύπου string και το grade (βαθμός) τύπου int. Διαβάστε τα περιεχόμενα του αρχείου που έχει δημιουργηθεί με τον κώδικα 1.19
(data_student_struct10.txt) και τοποθετήστε τα σε κατάλληλο πίνακα. Βρείτε τα ονόματα και το μέσο όρο βαθμολογίας των
σπουδαστών με βαθμό άνω του μέσου όρου όλων των σπουδαστών. Θεωρείστε ότι οι βαθμοί έχουν αποθηκευτεί στο αρχείο
data_student_struct10.txt ως ακέραιοι αριθμοί από το 0 μέχρι και το 100, αλλά η εμφάνισή τους θα πρέπει να γίνεται εφόσον
πρώτα διαιρεθούν με το 10. Δηλαδή, ο βαθμός 55 αντιστοιχεί στο βαθμό 5.5.
*/
#include <iostream>
#include <fstream>
#include <sstream>

struct student
{
    std::string name;
    double grade;
};

//Καταμέτρηση εγγραφών από αρχείο
int get_size()
{
    std::ifstream is;
    //FILE *fp;
    std::string line;
    int counter=0;
    is.open("data_student_struct10.txt",std::ios::in);
    //fp=fopen("data_student_struct10.txt","r");
    while(std::getline(is,line))
    //while(fgets(line,200,fp)!=NULL)
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        counter++;
    }
    is.close();
    //fclose(fp);
    return counter;
}

//Εισαγωγή δεδομένων από αρχείο σε πίνακα.
void read_data(student *stdns)
{
    std::ifstream is;
    std::string line;
    int i=0;
    is.open("data_student_struct10.txt",std::ios::in);
    while(std::getline(is,line))
    {
        if(line.size()==0) continue;
        if(line.at(0)=='#') continue;
        std::stringstream ss(line);
        ss>>stdns[i].name;
        ss>>stdns[i].grade;
        //In c
        //char *token=strtok(line," ");
        //while(token!=NULL)
        //{
        //  execute
        //  token=strtok(NULL,",");
        //}
        i++;
    }
    is.close();
}

//Εύρεση ζητούμενου
void execute(student *sts,int size)
{
    double average=0.0;
    double overall=0.0;
    for(int i=0;i<size;i++)
    {
        overall+=sts[i].grade;
    }
    overall/=(size*10.0);
    int cnt=0;
    std::cout<<"*********** OVER TOTAL AVERAGE ****************"<<std::endl;
    for(int i=0;i<size;i++)
    {
        if(sts[i]>overall)
        {
            std::cout<<"NAME:"<<sts[i].name<<"\t"<<"GRADE:"<<sts[i].grade/10.0<<std::endl;
            average+=sts[i].grade;
            cnt++;
        }
    }
    std::cout<<"*************************************************"<<std::endl;
    average/=(cnt*10.0);
    std::cout<<"AVERAGE OF STUDENTS THAT HAVE OVER THE TOTAL AVERAGE:"<<average<<std::endl;
}

int main(int argc,char **argv)
{
    student *students;
    int size=get_size();
    students=new student[size];//δέσμευση θέσεων μνήμης από τον δείκτη
    read_data(students);
    execute(students,size);
    delete[] students;//Διαγραφή δείκτη
}