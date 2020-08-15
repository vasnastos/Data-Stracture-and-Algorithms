/*
Να γραφεί συνάρτηση simple_stats που θα δέχεται ως παράμετρο έναν μονοδιάστατο πίνακα
ακεραίων και το πλήθος των στοιχείων του και επιστρέφει μέσω κλήσεων με αναφορά το μέσο όρο, το ελάχιστο και το μέγιστο
από όλα τα στοιχεία του πίνακα
*/
#include <iostream>

void simple_stats(int *a,int size,double &avg,int &max,int &min)
{
    int sum=a[0];
    max=min=a[0];
    for(int i=1;i<size;i++)
    {
       sum+=a[i];
       if(a[i]>max)
       {
           max=a[i];
       }
       if(a[i]<min)
       {
           min=a[i];
       }
    }
    avg=(double)sum/size;
}

int main(int argc,char **argv)
{
    int board[]{5,7,12,34,21,6,11,8,13};
    double avg;
    int max,min;
    simple_stats(board,sizeof(board)/sizeof(board[0]),avg,max,min);
    std::cout<<"AVERAGE:"<<avg<<std::endl;
    std::cout<<"MAX:"<<max<<std::endl;
    std::cout<<"MIN:"<<min<<std::endl;
}