#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        Backtrack(result,candidates,combination,target,0);
        return result;
    }

    void Backtrack(vector<vector<int>>& result,vector<int>& candidates,vector<int>& combination, int target,int start){
        if(target < 0)
            return;
        if(!target)
            result.push_back(combination);
        for(int i = start ; i<candidates.size();i++){
            if( i==start || candidates[i] != candidates[i-1]){//i==start to avoid underflow of [i-1]
            combination.push_back(candidates[i]);
            Backtrack(result,candidates,combination,target-candidates[i],i+1);
            combination.pop_back();
            }
        }
    }
};

int main(){
    Solution test;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    for (auto x:test.combinationSum2(candidates,target)){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return -1;
}