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

void depthFirstSearch_Recusive(Node *root){
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    depthFirstSearch_Recusive(root->left);
    depthFirstSearch_Recusive(root->right);
}   

void depthFirstSearch(Node *root){
    if(root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node *current = st.top();
        st.pop();
        cout<<current->data<<" ";
        if(current->right != nullptr)
            st.push(current->right);
        if(current->left != nullptr)
            st.push(current->left);
    }
}   

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    depthFirstSearch(root);
}