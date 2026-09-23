class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // lower_bound: first index with nums[i] >= target
        int left = lowerBound(nums, target);
        // upper_bound - 1: last index with nums[i] <= target
        int right = upperBound(nums, target) - 1;

        if (left > right) return {-1, -1};          // target absent
        return {left, right};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();               // [lo, hi)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) hi = mid;      // keep looking left
            else lo = mid + 1;
        }
        return lo;
    }

    int upperBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();               // [lo, hi)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) hi = mid;       // keep looking left
            else lo = mid + 1;
        }
        return lo;
    }
};