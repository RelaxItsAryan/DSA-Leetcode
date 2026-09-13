class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1, ones2;

        // Store coordinates of 1s in img1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    ones1.push_back({i, j});
                }
            }
        }

        // Store coordinates of 1s in img2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1) {
                    ones2.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, int> frequency;
        int answer = 0;

        // Try aligning every 1 in img1 with every 1 in img2
        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;

                frequency[{dr, dc}]++;
                answer = max(answer, frequency[{dr, dc}]);
            }
        }

        return answer;
    }
};