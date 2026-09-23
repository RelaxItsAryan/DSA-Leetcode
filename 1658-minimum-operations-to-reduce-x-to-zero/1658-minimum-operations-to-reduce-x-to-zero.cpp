class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        long long target = totalSum - x;

        if (target < 0) {
            return -1;
        }

        if (target == 0) {
            return nums.size();
        }

        int left = 0;
        long long windowSum = 0;
        int maxLength = -1;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            while (windowSum > target) {
                windowSum -= nums[left];
                left++;
            }

            if (windowSum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};