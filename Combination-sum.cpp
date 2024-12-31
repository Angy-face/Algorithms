#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        Backtrack(result,candidates,combination,target,0);
        return result;
    }
    void Backtrack(vector<vector<int>> &result,vector<int>& candidates,vector<int> &combination, int target,int start){
        if(0>target)
            return;
        if(!target)
            result.push_back(combination);
        for(int i = start;i<candidates.size();i++){
                combination.push_back(candidates[i]);
                Backtrack(result,candidates,combination,target-candidates[i],i);
                combination.pop_back();
        }
    }
};

int main(){
    Solution test;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    for (auto x:test.combinationSum(candidates,target)){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return -1;
}