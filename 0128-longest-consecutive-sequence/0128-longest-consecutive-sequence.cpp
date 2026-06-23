class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans;
        int n = nums.size();
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            ans.insert(nums[i]);
        }
        int maxi =1;
        for(int x:ans){
            if(ans.find(x-1)==ans.end()){
                int count =1;
                while(ans.find(x+1)!=ans.end()){
                    count++;
                    x++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};