class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n%2;
         n = n/2;
        while(n>0){
            int current = n%2;
            if (current == prev){
                return false;
            }
            prev = n%2;
            n = n/2;
        }
        return true;

    }
};