class Solution {
public:
    int findNext(vector<int>& nums2, int x){
        int index =-1;
        int n = nums2.size();
        for(int i =0; i<n; i++){
            if(nums2[i]==x){
                index = i;
                break;
            }
        }
        for(int j=index+1; j<n; j++){
            if(nums2[j]>x) return nums2[j];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp;
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++){
            mpp[nums1[i]]=i;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                ans[mpp[nums2[i]]]=findNext(nums2, nums2[i]);
            }
        }
        return ans;
    }
};