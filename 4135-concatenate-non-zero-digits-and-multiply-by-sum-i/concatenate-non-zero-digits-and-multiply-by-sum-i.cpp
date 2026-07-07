class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n ==0 )return n;
        long long ans = 0, sum = 0, len = 1;
        while(n>0){
            ans += (n%10)*len;
            if(n%10 != 0)len = len*10;
            sum += n%10;
            n = n/10;
        }
        return ans*sum;
    }
};