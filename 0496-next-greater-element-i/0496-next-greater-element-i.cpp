class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp;
        stack<int> st;
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++){
            mpp[nums1[i]]=i;
        }
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(mpp.find(nums2[i])!=mpp.end()){
                if(st.empty()) ans[mpp[nums2[i]]]=-1;
                else ans[mpp[nums2[i]]]=st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};