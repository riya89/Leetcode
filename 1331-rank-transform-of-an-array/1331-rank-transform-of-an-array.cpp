class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        vector<int> ans(arr.size(), 0);
        sort(sorted.begin(), sorted.end());
        map<int, int> ranks;
        int rank =1;
        for(int i=0; i<sorted.size(); i++){
            if(ranks.find(sorted[i]) == ranks.end()){
                ranks[sorted[i]]=rank;
                rank++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            ans[i]=ranks[arr[i]];
        }
        return ans;
    }
};