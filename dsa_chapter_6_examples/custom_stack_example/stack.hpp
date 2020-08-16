/*
  Στοίβες::
     • is_empty(), ελέγχει αν η στοίβα είναι άδεια.
     • size(), επιστρέφει το μέγεθος της στοίβας.
     • top(), προσπελαύνει το στοιχείο που βρίσκεται στη κορυφή της στοίβας (χωρίς να το αφαιρεί).
     • push(), ωθεί ένα στοιχείο στη κορυφή της στοίβας
     • pop(), αφαιρεί το στοιχείο που βρίσκεται στη κορυφή της στοίβας.
*/


#include "stack_list.cpp"

template <class T>
class stack
{
    private:
      stacklist <T> list;
    public:
      stack();
      ~stack();
      void push(T elem);
      void pop();
      T top();
      bool is_empty();
};