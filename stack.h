/*
 * 2020/10/14 DS Week3 Stack&Queue
 * Implement Stack
 * ADT and some code from textbook:<<Fundamentals Of Data Structures In C++>>
*/

template <class T>
class Stack
{
public:
    Stack(int stackCapacity = 10);
    ~Stack();
    bool IsEmpty() const;
    T &Top() const;
    void Push(const T &item);
    void Pop();
    void ChangeSize1D(int new_size);

private:
    T *stack;
    int top; // init. val = -1
    int capacity;
};