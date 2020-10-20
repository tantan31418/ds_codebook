#include"2_stack_queue.h"

// #include<iostream>
// using namespace std;
// included in header file

int main(){

    Two_St_Queue<int> q1;
    for (int i=0;i<7;i++){
        q1.Push(i);
    }
    for (int i=0;i<6;i++){
        q1.Pop();
    }
    for (int i=0;i<6;i++){
        q1.Push(i+10);
    }
    while (!q1.IsEmpty()){
        q1.Pop();
    }
    cout<<"hello"<<endl;

    return 0;
}