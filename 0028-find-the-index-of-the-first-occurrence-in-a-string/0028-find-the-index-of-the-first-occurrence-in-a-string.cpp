class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        string res = needle + '$' + haystack;
        vector<int> z(n+m+1,0);
        int l=0; int r=0;
        for(int i=1; i<n+m+1; i++){
            //inside the box
            if(i<=r){
                z[i]=min(z[i-l], r-i+1);
            }
            //extend
            while(i+z[i]<res.size() && res[z[i]]==res[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        for(int i=m+1; i<n+m+1; i++){
            if(z[i]==m) return (i-m-1);
        }
        return -1;
    }
};