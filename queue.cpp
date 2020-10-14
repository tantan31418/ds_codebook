#include"queue.h"

// #include<iostream>
// using namespace std;
// included in header file

int main(){

    Queue<int> q1(2);
    for (int i=0;i<7;i++){
        q1.Push(i);
    }
    for (int i=0;i<6;i++){
        q1.Pop();
    }
    for (int i=0;i<6;i++){
        q1.Push(i+10);
    }
    cout<<"hello"<<endl;

    return 0;
}