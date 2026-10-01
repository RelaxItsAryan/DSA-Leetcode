class Solution {
public:

    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {
        string res;

        // 100 - 999
        if (num >= 100) {
            res += below20[num / 100] + " Hundred";
            num %= 100;

            if (num != 0)
                res += " ";
        }

        // 20 - 99
        if (num >= 20) {
            res += tens[num / 10];
            num %= 10;

            if (num != 0)
                res += " ";
        }

        // 1 - 19
        if (num > 0) {
            res += below20[num];
        }

        return res;
    }

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        string ans;

        if (num >= 1000000000) {
            ans += helper(num / 1000000000) + " Billion";
            num %= 1000000000;

            if (num != 0)
                ans += " ";
        }

        if (num >= 1000000) {
            ans += helper(num / 1000000) + " Million";
            num %= 1000000;

            if (num != 0)
                ans += " ";
        }

        if (num >= 1000) {
            ans += helper(num / 1000) + " Thousand";
            num %= 1000;

            if (num != 0)
                ans += " ";
        }

        if (num > 0) {
            ans += helper(num);
        }

        return ans;
    }
};