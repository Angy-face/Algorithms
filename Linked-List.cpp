#include <bits/stdc++.h>
using namespace std;
#define endll endl

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data){
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

void printNodeSingleForward(Node *n){
    while(n!=nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
}
void printNodeSingleBack(Node *n){
    while(n!=nullptr){
        cout<<n->data<<" ";
        n = n->prev;
    }
}


int main(){
    // Siglely Linked List Test username Test Gmail
    Node *head = new Node(1);
    Node *sec  = new Node(2);
    Node *tail = new Node(3);

    head->next = sec;
    sec->next  = tail;
    printNodeSingleForward(head);

    // Doublely Linked list
    Node *head = new Node(1);
    Node *sec  = new Node(2);
    Node *tail = new Node(3);

    head->next = sec;
    sec->prev = head;
    sec->next  = tail;
    tail->prev = sec;
    printNodeSingleForward(head);
    printNodeSingleBack(tail);


    return 0;
}