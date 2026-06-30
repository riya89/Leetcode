class Solution {
public:
    int numberOfSubstrings(string s) {
        int count =0;
        int l =0; int r=0;
        int n = s.size();
        vector<int> freq(3, 0);
        while(r<n){
            freq[s[r]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0 ){
                count+= n-r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};