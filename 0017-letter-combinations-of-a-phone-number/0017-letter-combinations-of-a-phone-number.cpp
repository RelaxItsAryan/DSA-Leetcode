class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, mapping, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index,
                   const vector<string>& mapping,
                   string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            current.push_back(c);        
            backtrack(digits, index + 1, mapping, current, result);
            current.pop_back();          
        }
    }
};