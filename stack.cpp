/*
 * 2020/10/14 DS Week3 Stack&Queue
 * Implement Stack
 * ADT and some code from textbook:<<Fundamentals Of Data Structures In C++>>
*/

#include <iostream>
#include "stack.h"

using namespace std;

// test
int main(){
    // Stack<int> s1(0);
    Stack<int> s2(20);
    Stack<int> s3(5);
    for (int i=0;i<20;i++){
        s2.Push(i);
    }
    for (int i=0;i<10;i++){
        s3.Push(i);
    }
    // for (int i=0;i<10;i++){
    //     cout<<"s3.Top="<<s3.Top()<<"\n";   
    // }
    for (int i=0;i<10;i++){
        s3.Pop();   
    }
    return 0;
}