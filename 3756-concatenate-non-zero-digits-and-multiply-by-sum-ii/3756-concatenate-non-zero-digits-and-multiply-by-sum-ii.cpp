class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<int> digit;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        // powers of 10
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix digit sum
        vector<long long> prefSum(n + 1, 0);

        // prefix concatenated number
        vector<long long> prefNum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // first non-zero > r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            // no non-zero digits
            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long number =
                (prefNum[R + 1] -
                 (prefNum[L] * pow10[len]) % MOD +
                 MOD) % MOD;

            ans.push_back((number * (sum % MOD)) % MOD);
        }

        return ans;
    }
};