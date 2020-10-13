/*
 * 2020/10/13 DS Week3 Stack&Queue
*/

#include<iostream>
#include<string>
#include<stack>
//use stack to implement

using namespace std;

string conver_posfx(string infx);
int get_prec(char c);

int main(){
    string infx,posfx;
    cin>>infx;
    posfx = conver_posfx(infx);
    cout<<posfx<<endl;

    return 0;
}

int get_prec(char c){
    if (c=='+'||c=='-'){
        return 1;
    }
    else if (c=='*'||c=='\\'){
        return 2;
    }
    else{
        return 0;
    }
}

int is_op(char c){
    if (c=='+'||c=='-'||c=='*'||c=='\\'){
        return 1;
    }
    else {
        return 0;
    }
}


string conver_posfx(string infx){
    stack<char> st;
    int s_len = infx.length();
    string post;
    for (int i=0;i<s_len;i++){
        if (infx[i]=='('){
            post.push_back('(');
        }
        else if(infx[i]==')'){
            while(st.top()!='('){
                post.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (is_op(infx[i])){
            while (get_prec(st.top())>=get_prec(infx[i])){
                post.push_back(st.top());
                st.pop();
            }
            st.push(infx[i]);
        }
        else {
            post.push_back(infx[i]);
        }
    }
    return post;
}