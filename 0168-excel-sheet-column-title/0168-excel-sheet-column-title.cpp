class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber > 0) {
            columnNumber--;  // shift from 1..26 to 0..25
            char ch = 'A' + (columnNumber % 26);
            result.push_back(ch);
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};