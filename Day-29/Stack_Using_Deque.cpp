#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> deq;
public:
    void push(int data){
        deq.push_front(data);
    }
    void pop(){
        deq.pop_front();
    }
    int top(){
        return deq.front();
    }
};
int main(){
    Stack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    for(int i=1;i<=5;i++){
        cout<<s.top()<<endl;
        s.pop();
    }// 5 4 3 2 1
    return 0;
}