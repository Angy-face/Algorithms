#include <bits/stdc++.h>
using namespace std;
#define endll endl
#define MAX_SIZE 100

class Stack_Arr{
    private:
        int arr[MAX_SIZE];
        int top_index;

    public:
        Stack_Arr (){
            top_index = -1;
        }
        void push (int n){
            arr[++top_index] = n;
        }

        int pop(){
            return arr[top_index--];
        }

        int top(){
            return arr[top_index];
        }
};

class Node{
    public:
    int data;
    Node *prev;
};

class Stack{
    private:
    Node *top;

    public:
    Stack(){top = nullptr;}
    void push(int x){
        Node *newnode = new Node();
        newnode->data = x;
        newnode->prev = top;
        top = newnode;
    }

    int pop(){
        if (top == nullptr){
            cout<<endll<<"Stack Underflow";
            return 505;
        }
        Node *temp = top;
        int deleted = temp->data;
        top = top->prev;
        delete temp;
        return deleted;
    }

    int peek(){
        if (top == nullptr){
            cout<<endll<<"Stack is empty";
            return 505;
        }
        return top->data;
    }
};

int main(){

    Stack s;
    s.push(2);
    s.push(3);
    cout<<s.peek()<<s.pop()<<s.peek()<<s.peek()<<s.pop()<<s.peek();
    return -1;
}