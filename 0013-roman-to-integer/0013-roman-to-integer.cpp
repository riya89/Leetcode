class Solution {
public:
    int romanToInt(string s) {
        static vector<int> h= {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static vector<string> l= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        map<char, int> mpp{{'M', 1000}, {'D', 500}, {'C', 100}, {'L',50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int n = s.size();
        int ans =0;
        for(int i=0; i<n; i++){
            if(i<n-1 && mpp[s[i+1]]>mpp[s[i]]){
                ans+=(mpp[s[i+1]]-mpp[s[i]]);
                i++;
            }else{
                ans+=mpp[s[i]];
            }
        }
        return ans;
    }
};