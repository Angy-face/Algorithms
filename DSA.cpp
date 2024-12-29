#include <bits/stdc++.h>
using namespace std;
#define endll endl

void print(int n){
    cout<<n;
}

void process(int *arr,int size,int n,void (*callback)(int)){
    cout<<"Printed Array: ";
    for(int i = 0;i< size;i++)
        cout<<arr[i]<<" ";
    cout<<"Function called: ";
    callback(n);
    cout<<endll;
}

void numpyadd(vector<int> &vec,int n){
    for(int i = 0 ;i<vec.size();i++)
        vec[i]+=n;
}

struct Student
{
    string name;
    int age;
    float gpa;
};

class Person{
private:
    string name;
    int age;
public:
    Person(string n , int a){
        name = n;
        age = a;
    }

    void Greet (){
        cout<<"Hello "<<name<<" Age "<< age;
    }
};
int main(){
    // int arr[4] = {1,2,3,4};
    // vector<int> vec = {1,2,3,4};
    // process(arr,sizeof(arr)/sizeof(arr[0]),69,print);

    // numpyadd(vec,5);
    // for (auto x:vec){
    //     cout<<x<<" ";
    // }

    // Student student1;
    // student1.age = 20;
    // student1.gpa = 4.00;
    // student1.name = "Banana";
    // cout<<student1.age<<" "<<student1.gpa<<" "<<student1.name;

    Person person1("Name",18);
    person1.Greet();
    cout<<person1.age;

    return 0;
}