class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    if (n <= 1) return;

    // 1. Find pivot: first i from right such that nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        // 2. Find successor: first j from right such that nums[j] > nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        swap(nums[i], nums[j]);
    }

    // 3. Reverse suffix starting from i+1
    reverse(nums.begin() + i + 1, nums.end());
    }
};