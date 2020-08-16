#include "queue.hpp"

template <class T>queue<T>::queue() {}

template <class T>void queue<T>::push(T d)
{
    this->list.push_back(d);
}

template <class T>void queue<T>::pop()
{
    this->list.popfront();
}

template <class T>bool queue<T>::isEmpty()
{
    return this->list.isempty();
}

template <class T>int queue<T>::size()
{
    return this->list.length();
}

template <class T>T queue<T>::front()
{
    return this->list.front();
}

template <class T>T queue<T>::back()
{
    return this->list.back();
}

template <class T>queue<T>::~queue() {}