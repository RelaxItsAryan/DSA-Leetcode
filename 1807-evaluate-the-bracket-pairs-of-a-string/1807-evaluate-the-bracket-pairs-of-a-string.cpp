class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        
        // Store key -> value
        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            } 
            else {
                // Extract key inside brackets
                string key = "";
                i++;  // move after '('
                
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                
                // Replace (key) with its value, otherwise '?'
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            }
        }
        
        return ans;
    }
};