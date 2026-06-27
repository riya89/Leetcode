class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> mpp;
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        int count =1;
        if(mpp[1]){
            if(mpp[1]%2==0) count=max(count, mpp[1]-1);
            else count = max(count, mpp[1]);
        }
        for(auto it : mpp){
            long long n = it.first;
            int ans =0;
            if(n==1) continue;
            while(mpp[n]>=2){
                ans+=2;
                n = n*n;
                if(n>1e9) break;
            } //at end of loop n might be center
            if(mpp[n]>=1){
                ans++;
            }else{
                ans--;
            }
            count=max(ans, count);
        }
        return count;
    }
};