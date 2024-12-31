#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> subset;
        Backtrack(nums,result,subset,0);
    return result;        
    }

    void Backtrack(vector<int> &nums,vector<vector<int>> &result,vector<int> &subset,int start){
        result.push_back(subset);
        for(int i = start ;i<nums.size();i++){
            subset.push_back(nums[i]);
            Backtrack(nums,result,subset,i+1);
            subset.pop_back();
        }
    }
};

int main(){
    Solution test;
    vector<int> nums = {1,2,3};
    for (auto x:test.subsets(nums)){
        cout<<"[";
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<"] ";
    }
    return -1;
}