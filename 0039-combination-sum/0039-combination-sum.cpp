class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());  // optional, helps pruning

        function<void(int, int)> backtrack = [&](int start, int remain) {
            if (remain == 0) {
                res.push_back(path);
                return;
            }
            if (remain < 0) return;

            for (int i = start; i < (int)candidates.size(); ++i) {
                if (candidates[i] > remain) break;  // pruning

                path.push_back(candidates[i]);
                backtrack(i, remain - candidates[i]);  // reuse same index
                path.pop_back();
            }
        };

        backtrack(0, target);
        return res;
    }
};


