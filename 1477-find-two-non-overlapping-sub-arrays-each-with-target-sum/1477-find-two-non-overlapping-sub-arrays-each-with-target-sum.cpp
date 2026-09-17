#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> bestLeft(n, INF), bestRight(n, INF);

        // Forward pass: bestLeft[i] = min length of subarray with sum=target ending at or before i
        int left = 0, sum = 0;
        int minLen = INF;
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target && left <= right) {
                sum -= arr[left];
                ++left;
            }
            if (sum == target) {
                int len = right - left + 1;
                minLen = min(minLen, len);
            }
            bestLeft[right] = minLen;
        }

        // Backward pass: bestRight[i] = min length of subarray with sum=target starting at or after i
        left = n - 1;
        sum = 0;
        minLen = INF;
        for (int right = n - 1; right >= 0; --right) {
            sum += arr[right];
            while (sum > target && left >= right) {
                sum -= arr[left];
                --left;
            }
            if (sum == target) {
                int len = left - right + 1;
                minLen = min(minLen, len);
            }
            bestRight[right] = minLen;
        }

        int ans = INF;
        for (int i = 0; i + 1 < n; ++i) {
            if (bestLeft[i] != INF && bestRight[i + 1] != INF) {
                ans = min(ans, bestLeft[i] + bestRight[i + 1]);
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};