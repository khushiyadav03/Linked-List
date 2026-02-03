class Solution {
public:
    bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    if (n < 4) return false;

    int i = 0;
    int phase = 0;

    while (i + 1 < n) {
        if (phase == 0) {
            if (nums[i] < nums[i + 1]) i++;
            else if (nums[i] > nums[i + 1]) {
                if (i == 0) return false; // first increasing missing
                phase = 1;
                i++;
            } else return false;
        }
        else if (phase == 1) {
            if (nums[i] > nums[i + 1]) i++;
            else if (nums[i] < nums[i + 1]) {
                phase = 2;
                i++;
            } else return false;
        }
        else {
            if (nums[i] < nums[i + 1]) i++;
            else return false;
        }
    }
    return phase == 2;
}

};