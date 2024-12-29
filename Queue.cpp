#include <bits/stdc++.h>
#define SIZE 5
using namespace std;

//isFull isEmpty enqueue dequeue SIZE5
class QueueArr{
    private:
        int Q[SIZE];
        int front;
        int rear;
    public:
        QueueArr(){front = -1 , rear = -1;}

        int isFull(){
            return rear == SIZE-1;
        }
        int isEmpty(){
            return front == -1;
        }
        void enqueue(int element){
            if (isFull()){
                cout<<"Q is Full"<<endl;
                return;
            }
            if(isEmpty())
                front = 0;
            Q[++rear] = element;
        }
        int dequeue(){
            if (rear <= front){
                cout<<"Q is Empty"<<endl;
                return -1;
            }
           return Q[front++]; 
        }
        void show(){
            for(int i = front ; i <= rear ; i++)
                cout<<Q[i]<<" ";
            cout<<endl;    
        }

};
int main(){
    QueueArr Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.show();

    Q.dequeue();
    Q.show();
    Q.dequeue();
    Q.show();

    return -1;
}