#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> numbers;

        for (int i = 0; i < n; ++i) {
            // Units digit must be even
            if (digits[i] % 2 != 0) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                // Do not reuse the same copy
                if (j == i) {
                    continue;
                }

                for (int k = 0; k < n; ++k) {
                    // Do not reuse the same copy
                    if (k == i || k == j) {
                        continue;
                    }

                    // Hundreds digit cannot be zero
                    if (digits[k] == 0) {
                        continue;
                    }

                    int number = digits[k] * 100 +
                                 digits[j] * 10 +
                                 digits[i];

                    numbers.insert(number);
                }
            }
        }

        return numbers.size();
    }
};