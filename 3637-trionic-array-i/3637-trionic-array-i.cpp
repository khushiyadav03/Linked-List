class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]>nums[1] || nums[n-2]>nums[n-1]) return false;
        int i = 0;
        while(i<nums.size()-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i==nums.size()-1){
            return false;
        }
        while(i<nums.size()-1 && nums[i]>nums[i+1]){
            i++;
        }
        if(i==nums.size()-1){
            return false;
        }
        while(i<nums.size()-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i==nums.size()-1){
            return true;
        }
        return false;

    }
};