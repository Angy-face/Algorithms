class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash; 
    for(int i = 0 ; i < nums.size() ; i++){
        if (hash[nums[i]] != 0){
            if (hash[nums[i]] == -1){
                return {0,i};
            }
            return {hash[nums[i]],i};
        }
        hash[target - nums[i]] = (i == 0)? -1 :i;
        }
    return {-69,-420};
    }
};