#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        Backtrack(nums,result,permutation);
        return result;
    }
    void Backtrack(vector<int> &nums,vector<vector<int>> &result,vector<int> &permutation){
        if(permutation.size() == nums.size())
            result.push_back(permutation);

        for(int i = 0 ;i<nums.size();i++){
            if(!isDuplicated(nums[i],permutation)){
                permutation.push_back(nums[i]);
                Backtrack(nums,result,permutation);
                permutation.pop_back();
            }
        }
    }
    bool isDuplicated(int n,vector<int> &permutation){
        for(int i =0;i<permutation.size();i++)
            if(n == permutation[i])
                return true;
        return false;
    }
};

int main(){
    Solution test;
    vector<int> nums = {1,2,3};
    for (auto x:test.permute(nums)){
        for (auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return -1;
}