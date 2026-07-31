class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= 1; j++) {
                int l = i, r = i + j;

                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > len) {
                        len = r - l + 1;
                        start = l;
                    }
                    l--;
                    r++;
                }
            }
        }

        return s.substr(start, len);
    }
};