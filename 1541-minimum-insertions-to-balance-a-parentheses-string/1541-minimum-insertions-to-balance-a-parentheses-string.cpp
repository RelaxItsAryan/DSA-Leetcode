class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++open;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    ++i;
                } else {
                    ++insertions;
                }

                if (open == 0) {
                    ++insertions;
                } else {
                    --open;
                }
            }
        }
        return insertions + 2 * open;
    }
};