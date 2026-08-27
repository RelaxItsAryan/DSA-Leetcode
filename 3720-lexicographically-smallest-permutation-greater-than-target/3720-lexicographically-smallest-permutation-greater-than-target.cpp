class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        vector<int> used(26, 0);

        // Initially consider the prefix target[0...n-2]
        for (int i = 0; i < n - 1; i++) {
            used[target[i] - 'a']++;
        }

        // Try the rightmost possible position for the first greater character
        for (int i = n - 1; i >= 0; i--) {
            bool canMatchPrefix = true;

            for (int c = 0; c < 26; c++) {
                if (used[c] > cnt[c]) {
                    canMatchPrefix = false;
                    break;
                }
            }

            if (canMatchPrefix) {
                int current = target[i] - 'a';
                int chosen = -1;

                // Choose the smallest available character greater than target[i]
                for (int c = current + 1; c < 26; c++) {
                    if (cnt[c] - used[c] > 0) {
                        chosen = c;
                        break;
                    }
                }

                if (chosen != -1) {
                    string answer = target.substr(0, i);
                    answer += char('a' + chosen);

                    used[chosen]++;

                    // Append remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {
                        int remaining = cnt[c] - used[c];
                        answer.append(remaining, char('a' + c));
                    }

                    return answer;
                }
            }

            // For the next iteration, remove target[i - 1] from the prefix
            if (i - 1 >= 0) {
                used[target[i - 1] - 'a']--;
            }
        }

        return "";
    }
};