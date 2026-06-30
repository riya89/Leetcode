class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        int i =0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign = +1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if (s[i]=='+'){
            sign=+1;
            i++;
        }
        while(i<n && isdigit(s[i])){

            long long temp = s[i] - '0';
            if(sign == 1 && (ans > INT_MAX/10 || (ans == INT_MAX/10 && temp > 7)))
                return INT_MAX;

            if(sign == -1 && (ans > INT_MAX/10 || (ans == INT_MAX/10 && temp > 8)))
                return INT_MIN;

            ans = ans*10*1LL + temp;
            i++;
        }

        return (int)(ans * sign);
    }
};