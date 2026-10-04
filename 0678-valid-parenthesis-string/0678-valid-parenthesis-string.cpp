class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // Treat '*' as ')' for minimum possible opens
                high++;  // Treat '*' as '(' for maximum possible opens
            }

            // Unmatched '(' count cannot be negative
            low = max(low, 0);

            // Too many ')' and no possible '(' to match them
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};