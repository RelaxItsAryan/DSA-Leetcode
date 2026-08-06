class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int temp = n;
            int product = 1;

            if (temp == 0)
                product = 0;

            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};