class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        // Length of sequential number
        for (int len = 2; len <= 9; len++) {

            // Starting digit
            for (int start = 1; start <= 10 - len; start++) {

                int num = 0;

                // Build the number
                for (int digit = start; digit < start + len; digit++) {
                    num = num * 10 + digit;
                }

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};