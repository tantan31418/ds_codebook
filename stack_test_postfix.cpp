#include "stack.h"
/*
 * 2020/10/14 DS Week3 Stack&Queue
 * Use my stack to implement postfix convert
*/
#include <iostream>
#include <string>
#define DEBUG 0

using namespace std;

string conver_posfx(string infx);
int get_prec(char c);

int main()
{
    string infx, posfx;
    cin >> infx;
    posfx = conver_posfx(infx);
    cout << posfx << endl;

    return 0;
}

int get_prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '\\')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int is_op(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '\\')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string conver_posfx(string infx)
{
    Stack<char> st;
    infx = '(' + infx + ')'; //to initialize
    int s_len = infx.length();
    string post;
    for (int i = 0; i < s_len; i++)
    {
        if (DEBUG)
            cout << "line53" << endl;
        if (infx[i] == '(')
        {
            st.Push('(');
        }
        else if (infx[i] == ')')
        {
            while (st.Top() != '(')
            {
                if (DEBUG)
                    cout << "line59" << endl;
                post.push_back(st.Top());
                st.Pop();
            }
            st.Pop();
        }
        else if (is_op(infx[i]))
        {
            while (get_prec(st.Top()) >= get_prec(infx[i]))
            {
                post.push_back(st.Top());
                st.Pop();
            }
            st.Push(infx[i]);
        }
        else
        {
            post.push_back(infx[i]);
        }
    }
    return post;
}


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