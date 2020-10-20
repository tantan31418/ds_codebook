/*
 * 2020/10/20 DS Week3 Stack&Queue
 * Homework Q6
 * Implement Queue using two stacks
 * ADT and some code from textbook:<<Fundamentals Of Data Structures In C++>>
*/

#ifndef STACK_2_QUEUE
#define STACK_2_QUEUE
#include <stack> // use stack from STL
#include <iostream>
using namespace std;

template <class T>
class Two_St_Queue
{
public:
    Two_St_Queue();
    ~Two_St_Queue();
    bool IsEmpty() const;
    T &Front() const;
    T &Rear() const;
    void Push(const T &item);
    void Pop();

private:
    int capacity;
    int top1, top2;
    stack<T> ST1;
    stack<T> ST2;
};

template <class T>
Two_St_Queue<T>::Two_St_Queue()
{
    // if (capacity < 1)
    //     throw "Capacity must be >0";

    // ST1 = stack<T> s;
    // ST2 = stack<T> s;
    cout << "Queue initialized..." << endl;
}

template <class T>
Two_St_Queue<T>::~Two_St_Queue()
{
    // ST1.~T();
    // ST2.~T();
    cout << "Queue destroyed." << endl;
}

template <class T>
bool Two_St_Queue<T>::IsEmpty() const
{
    return ST1.empty();
}

template <class T>
T &Two_St_Queue<T>::Front() const
{
    if (IsEmpty())
        throw "Queue is empty.";
    while (!ST1.empty()){
        ST2.push(ST1.top());
        ST1.pop();
    }
    T front = ST2.top();
    while (!ST2.empty()){
        ST1.push(ST2.top());
        ST2.pop();
    }
    return front;
}

template <class T>
T &Two_St_Queue<T>::Rear() const
{
    if (IsEmpty())
        throw "Queue is empty.";
    return ST1.top();
}

template <class T>
void Two_St_Queue<T>::Push(const T &item)
{
    ST1.push(item);
    cout << "Push " << item << " to queue." << endl;
}

template <class T>
void Two_St_Queue<T>::Pop()
{
    if (IsEmpty())
        throw "Queue is empty. Cannot delete.";
    while (!ST1.empty()){
        ST2.push(ST1.top());
        ST1.pop();
    }
    T temp = ST2.top();
    ST2.pop();
    while (!ST2.empty()){
        ST1.push(ST2.top());
        ST2.pop();
    }
    cout << "Pop " <<temp<< " from queue." << endl;
}

#endif