#include "stack.hpp"

template <class T>stack<T>::stack() {}

template <class T>void stack<T>::push(T d)
{
    list.push_front(d);
}

template <class T>void stack<T>::pop()
{
    list.erase_front();
}

template <class T>bool stack<T>::is_empty()
{
    return list.is_empty();
}

template <class T>T stack<T>::top()
{
    return list.front();
}

template <class T>stack<T>::~stack() {}