class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int l=0; int r=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                r++; i++;
            }
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        if(r==0)
        return "";
        return s.substr(0, r - 1);
    }
};