class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum =0;
        long long newNum = 0;
        stack<int> st;
        while(n){
            int last = n%10;
            n = n/10;
            if(last!=0){
                st.push(last);
                sum+= last;
            }
        }
        while(!st.empty()){
            newNum = newNum*10+ st.top();
            st.pop();
        }
        return sum*newNum;
    }
};