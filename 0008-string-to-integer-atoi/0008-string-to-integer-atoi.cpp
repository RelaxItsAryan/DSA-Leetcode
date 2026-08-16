#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        int result = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            ++i;
        }
        
        return sign * result;
    }
};