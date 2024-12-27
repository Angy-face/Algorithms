class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size()-1;
        int mid = 69420;
        while (lower <= upper){
            mid = (lower+upper)/2;
            if(nums[mid] >= target)
                upper = mid-1;
            else
                lower = mid+1;
        }
        return lower;
    }
};