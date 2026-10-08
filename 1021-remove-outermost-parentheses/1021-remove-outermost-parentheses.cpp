class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                // If already inside a primitive, keep this '('
                if (depth > 0) {
                    ans += ch;
                }
                depth++;
            } 
            else { // ch == ')'
                depth--;

                // If still inside a primitive, keep this ')'
                if (depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};