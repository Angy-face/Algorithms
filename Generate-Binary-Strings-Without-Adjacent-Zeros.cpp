#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string generated;
        Backtrack(result,generated,n,0);
        return result;
    }

    void Backtrack(vector<string> &result,string generated,int n,int index){
        char sett[2] = {'0','1'};
        if(index > 1 &&generated[index-1]=='0' && generated[index-2]=='0'){
            return;}
        if (generated.length() == n){
            result.push_back(generated);
            return;
            }
        for(int i =0;i<2;i++){
                generated.push_back(sett[i]);
                Backtrack(result,generated,n,index+1);
                generated.pop_back();
        }
    }
};

int main(){
    Solution test;
    int target = 3;
    for (auto x:test.validStrings(target)){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return -1;
}