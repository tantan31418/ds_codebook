/*
 * 2020/10/14 DS Week3 Stack&Queue
 * Implement Queue
 * ADT and some code from textbook:<<Fundamentals Of Data Structures In C++>>
*/

#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    Queue(int queueCapacity = 10);
    ~Queue();
    bool IsEmpty() const;
    T &Front() const;
    T &Rear() const;
    void Push(const T &item);
    void Pop();
    void ChangeSize1D(int new_size);

private:
    T *queue;
    int front, rear; // init. val = -1
    int capacity;
};

template <class T>
Queue<T>::Queue(int stackCapacity) : capacity(stackCapacity)
{
    if (capacity < 1)
        throw "Capacity must be >0";
    queue = new T[capacity];
    front = 0;
    rear = 0;
    cout << "Queue initialized..." << endl;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue;
    cout << "Queue destroyed." << endl;
}

template <class T>
bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
T &Queue<T>::Front() const
{
    if (IsEmpty())
        throw "Queue is empty.";
    return queue[(front + 1) % capacity];
}

template <class T>
T &Queue<T>::Rear() const
{
    if (IsEmpty())
        throw "Queue is empty.";
    return queue[rear];//rear points to the last element
}

template <class T>
void Queue<T>::Push(const T &item)
{
    if ((rear + 1) % capacity == front) //queue full
    {
        ChangeSize1D(2 * capacity);
        capacity *= 2;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = item;
    cout << "Push " << queue[rear] << " to queue." << endl;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty())
        throw "Queue is empty. Cannot delete.";
    front = (front + 1) % capacity;
    cout << "Pop " << queue[front] << " from queue." << endl;
    queue[front].~T();
}

template <class T>
void Queue<T>::ChangeSize1D(int new_size)
{
    T *newqueue = new T[new_size];
    int start = (front+1)%capacity;
    if (start < 2)
    { //front==0||front==capacity-1,no wrap
        int new_pos = 0
        for (int i = start; i <= rear; i++)
        {
            newqueue[new_pos] = queue[i];
            new_pos++;
        }
    }
    else
    {
        int new_pos = 0;
        for (int i = front + 1; i < capacity; i++)
        {
            newqueue[new_pos] = queue[i];
            new_pos++;
        }
        for (int i = 0; i < front; i++)
        {
            newqueue[new_pos] = queue[i];
            new_pos++;
        }
    }
    front = new_size-1;
    rear = capacity-2;
    capacity = new_size;
    delete[] queue;
    queue = newqueue;
    cout << "New queue size is" << new_size << ".\n";
}