class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        vector<string> ans;
        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string cur = q.front();
                q.pop();

                if (isValid(cur)) {
                    ans.push_back(cur);
                    found = true;
                }

                // Do not generate longer-removal strings once an answer is found
                if (found) continue;

                for (int i = 0; i < (int)cur.size(); i++) {
                    if (cur[i] != '(' && cur[i] != ')') continue;

                    string next = cur.substr(0, i) + cur.substr(i + 1);

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) break;
        }

        return ans;
    }

private:
    bool isValid(const string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }

        return balance == 0;
    }
};