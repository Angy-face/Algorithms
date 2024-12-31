class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        Backtrack(result,candidates,combination,target,0);
        return result;
    }
    void Backtrack(vector<vector<int>> &result,vector<int>& candidates,vector<int> &combination, int target,int start){
        if(Sum(combination)>target)
            return;
        if(Sum(combination)==target)
            result.push_back(combination);
        for(int i = start;i<candidates.size();i++){
                combination.push_back(candidates[i]);
                Backtrack(result,candidates,combination,target,i);
                combination.pop_back();
        }
    }
    int Sum(vector<int> &combination){
        int sum = 0;
        for(auto x:combination)
            sum+=x;
        return sum;
    }
};