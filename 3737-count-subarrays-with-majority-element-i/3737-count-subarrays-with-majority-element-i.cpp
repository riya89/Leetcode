class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target) nums[i]=1;
            else nums[i]=-1;
        }
        vector<int> prefixSum;
        int sum =0;
        prefixSum.push_back(sum);
        for(int i=0; i<n; i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        int count=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(prefixSum[i]-prefixSum[j]>0) count++;
            }
        }
        return count;
    }
};