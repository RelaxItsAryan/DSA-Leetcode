class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(256, 0);

        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;

            while (count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};