#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int dest;
        int weight;
    Node(int x,int w):dest(x),weight(w){}
};
class Graph{
    public:
        int size;
        vector<list<Node>> adjList;
        bool isdirected;
        Graph(int x):size(x),adjList(x),isdirected(true){}

        void addEdge(int src,int dest,int weight = 1){
            adjList[src].push_back(Node(dest,weight));
            if(!isdirected)
                adjList[dest].push_back(Node(src,weight));
        }

        void show(){
            for(int i = 0 ;i < size ; i++){
                cout<<i<<" : ";
                for (Node x : adjList[i])
                    cout<<x.dest<<"("<<x.weight<<") ";
                cout<<endl;
            }
        }

};

int main(){
    Graph test(5);
    test.addEdge(0,1);
    test.addEdge(0,4);
    test.addEdge(1,2);
    test.addEdge(1,3);
    test.addEdge(1,4);
    test.addEdge(2,3);
    test.addEdge(3,4);

    test.show();
    return -1;
}