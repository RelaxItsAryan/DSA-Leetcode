class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char ch : seq) {
            if (ch == '(') {
                depth++;                  // enter this nesting level
                ans.push_back(depth % 2); // assign based on its level
            } 
            else {
                ans.push_back(depth % 2); // still at this level
                depth--;                  // leave the nesting level
            }
        }

        return ans;
    }
};