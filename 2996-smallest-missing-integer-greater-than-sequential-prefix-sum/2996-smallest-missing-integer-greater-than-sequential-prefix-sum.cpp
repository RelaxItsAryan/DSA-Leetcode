
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];

        // Find the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            prefixSum += nums[i];
        }

        // Store all numbers in the array
        unordered_set<int> present(nums.begin(), nums.end());

        // Find the smallest missing integer >= prefixSum
        int answer = prefixSum;

        while (present.count(answer)) {
            answer++;
        }

        return answer;
    }
};