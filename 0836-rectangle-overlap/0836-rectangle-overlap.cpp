class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 = [x1, y1, x2, y2], rec2 = [x3, y3, x4, y4]
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];

        // Check for non-overlapping conditions
        bool noOverlap = (x3 >= x2) ||  // rec2 is to the right
                         (x4 <= x1) ||  // rec2 is to the left
                         (y3 >= y2) ||  // rec2 is above
                         (y4 <= y1);    // rec2 is below

        return !noOverlap;
    }
};