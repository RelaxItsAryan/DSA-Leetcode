class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best;
        int bestLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') ones++;
                if (ones > k) break;          
                if (ones == k) {
                    int len = j - i + 1;
                    string sub = s.substr(i, len);
                    if (len < bestLen) {
                        bestLen = len;
                        best = sub;
                    } else if (len == bestLen && sub < best) {
                        best = sub;          
                    }
                }
            }
        }
        return best;   
    }
};