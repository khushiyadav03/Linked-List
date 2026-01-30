class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int n = nums.size();
        int expected = 1;
        for(int i = 0; i<n; i++){
            while(expected < nums[i]){
                ans.push_back(expected);
                expected++;
            }

            if(nums[i] == expected){
                expected++;
            }
        }

        while(expected <= n){
            ans.push_back(expected);
            expected++;
        }

        return ans;
    }
};