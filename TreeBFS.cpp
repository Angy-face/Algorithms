#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x){
            data = x;
            left = nullptr;
            right =nullptr;
        }
};

void breathFirstSearch(Node *root){
    if(root == nullptr)
        return;

    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()){
        Node* current = Q.front();
        Q.pop();
        cout<<current->data<<" ";
        if(current->left != nullptr)
            Q.push(current->left);
        if(current->right != nullptr)
            Q.push(current->right); 
    }
}   

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    breathFirstSearch(root);
}