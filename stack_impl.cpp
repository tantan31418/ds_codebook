/*
 * 2020/10/14 DS Week3 Stack&Queue
 * Implement Stack
 * ADT and some code from textbook:<<Fundamentals Of Data Structures In C++>>
*/

#include <iostream>
#include "stack.h"

using namespace std;


template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
    if (capacity < 1)
        throw "Capacity must be >0";
    stack = new T[capacity];
    top = -1;
    cout<<"Stack initialized..."<<endl;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] stack;
    cout<<"Stack destroyed."<<endl;
}

template <class T>
bool Stack<T>::IsEmpty() const
{
    return top == -1;
}

template <class T>
T &Stack<T>::Top() const
{
    if (IsEmpty())
        throw "Stack is empty.";
    return stack[top];
}

template <class T>
void Stack<T>::Push(const T &item)
{
    if (top == capacity - 1)
    {
        ChangeSize1D(2 * capacity);
        capacity *= 2;
    }
    stack[++top] = item; //top++,then push element to stack[top+1]
    cout<<"Push "<<stack[top]<<" to stack."<<endl;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        throw "Stack is empty. Cannot delete.";
    cout<<"Pop "<<stack[top]<<" from stack."<<endl;
    stack[top--].~T(); //Delete the element at stack[top], then top--
}

template <class T>
void Stack<T>::ChangeSize1D(int new_size)
{
    T *newstack = new T[new_size];
    for (int i = 0; i < capacity; i++)
    {
        newstack[i] = stack[i];
    }
    delete[] stack;
    stack = newstack;
    cout<<"New stack size is"<<new_size<<".\n";
}