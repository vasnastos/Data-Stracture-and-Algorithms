/*
Γράψτε ένα πρόγραμμα που να γεμίζει έναν πίνακα με όνομα board, 5 γραμμών και 5 στηλών, με τυχαίες ακέραιες τιμές
στο διάστημα 1 έως και 1000 (χρησιμοποιήστε ως seed την τιμή 12345). Γράψτε μια συνάρτηση που να δέχεται ως
παράμετρο τον πίνακα board και να επιστρέφει σε μονοδιάστατο πίνακα με όνομα col το άθροισμα των τιμών κάθε στήλης
του πίνακα. Οι τιμές που επιστρέφονται να εμφανίζονται στο κύριο πρόγραμμα το οποίο να εμφανίζει επιπλέον και τον
αριθμό στήλης με το μεγαλύτερο άθροισμα.
*/
#include <iostream>
#include <random>

void function(int board[][5],int s,int *col,int &cn)
{
    for(int j=0;j<s;j++)
    {
        col[j]=0;
        for(int i=0;i<s;i++)
        {
            col[j]+=board[i][j];
        }
    }
    cn=0;
    int max=col[0];
    for(int i=1;i<s;i++)
    {
       if(col[i]>max)
       {
           max=col[i];
           cn=i;
       }
    }
}

int main()
{
    std::mt19937 mt(12345);//srand(12345)
    std::uniform_int_distribution<int> dist(0, 1000);//rand()%1000.
    int board[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            board[i][j]=dist(mt);
        }
    }
    int maxcol;
    int columns[5];
    function(board,5,columns,maxcol);
    std::cout<<"**********************  Accumulate per Column *********************"<<std::endl;
    for(int i=0;i<5;i++)
    {
        std::cout<<"Column "<<i+1<<":"<<columns[i]<<std::endl;
    }
    std::cout<<"*******************************************************************"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Column with max sum is:"<<maxcol+1<<std::endl;
}