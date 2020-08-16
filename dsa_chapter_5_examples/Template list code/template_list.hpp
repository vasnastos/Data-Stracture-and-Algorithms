/*
Στα ακόλουθο αρχείο πραγματοποιήται η υλοποίηση μίας template class η οποία 
κατασκευάζει λίστα για οποιονδήποτε τύπο δεδομένων.
Το παρακάτω αρχείο πραγματοποιεί την δήλωση των συναρτήσεων μελών της κλάσης.
*/

#include <iostream>
template <class T>
struct node
{
    T data;
    node *next;
};

template <class T>
class list
{
  private:
    node <T> *head;
  public:
    list(); 
    list(T d);
    ~list();
    int length();
    bool is_Empty();
    T front();
    T back();
    void erase_front();
    void erase(int position);
    void insert(int position,T d);
    void pop_back();
    void push_back(T d);
    void push_front(T d);
    void print_list();
    void reverse();
    void bubblesort();
    void selection_sort();
    friend std::ostream &operator<<(std::ostream &os,const list <T> &ll);
};