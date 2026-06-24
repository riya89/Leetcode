class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it :mpp){
            pq.push({it.second, it.first});
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            int val = it.second;
            ans.push_back(val);
        }
        return ans;
    }
};