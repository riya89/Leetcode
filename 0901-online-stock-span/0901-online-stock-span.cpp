class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner() {
        st.push({-1, -1});
        index =0;
    }
    //previous greater element approach
    int next(int price) {
        int ans =0;
        while(st.top().first!=-1 && st.top().first<=price){
            st.pop();
        }
            int i = st.top().second;
            st.push({price, index});
            ans=(index-i);
            index++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */