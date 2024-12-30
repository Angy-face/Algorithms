#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int priority;// 1 > 2 > 3
        Node *next;
        Node(int d,int p){
            data = d;
            priority = p;
            next = nullptr; 
        }
};
class PriorityQueue{
    private:
        Node *head;
    public:
        PriorityQueue(){head = nullptr;}

        void enqueue(int d,int p){
            Node *newNode = new Node(d,p);
            if(head == nullptr ||  p < head->priority ){
                newNode->next = head;
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr && p >= temp->next->priority){//No need to check head again [temp->next->priority]
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void dequeue(){
            if(head == nullptr)
                return;
            Node *temp = head;
            cout<<"Dequeue: "<<head->data<<"["<<head->priority<<"]"<<endl;
            head = head->next;
            delete temp;
        }
        void show(){
            Node *temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"["<<temp->priority<<"] ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    PriorityQueue Q;
    Q.enqueue(1,1);
    Q.enqueue(2,2);
    Q.enqueue(3,2);
    Q.show();

    Q.dequeue();
    Q.show();
    Q.dequeue();
    Q.show();

    return -1;
}