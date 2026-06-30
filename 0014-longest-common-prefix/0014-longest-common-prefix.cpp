class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int s = strs.size();
        int i =0; int n = strs[0].size();
        int j =0; int m = strs[s-1].size();
        string ans = "";
        if(strs.empty()) return ans;
        while(i<n || j<m){
            if(strs[0][i]!=strs[s-1][j]) break;
            //matching
            ans+=strs[0][i];
            i++; j++;
        }
        return ans;
    }
};