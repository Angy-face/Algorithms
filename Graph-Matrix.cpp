#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int size;
        vector<vector<int>> adjList;
        bool isdirected;
        Graph(int x):size(x),adjList(x,vector<int>(x,0)),isdirected(true){}

        void addEdge(int src,int dest){
            adjList[src][dest] = 1;
            if(!isdirected)
                adjList[dest][src] = 1;
        }

        void show(){
            for(int i = 0 ;i < size ; i++){
                cout<<i<<" : ";
                for(int j = 0 ;j <adjList.size();j++)
                    if(adjList[i][j])
                        cout<<j<<" ";            
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