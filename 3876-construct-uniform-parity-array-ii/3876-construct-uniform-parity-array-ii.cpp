#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }

        // Already all odd or all even
        if (minOdd == INT_MAX || minEven == INT_MAX) {
            return true;
        }

        // Mixed parity: smallest element must be odd
        return minOdd < minEven;
    }
};