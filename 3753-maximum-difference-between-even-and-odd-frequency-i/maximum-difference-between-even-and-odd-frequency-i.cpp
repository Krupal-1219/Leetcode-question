class Solution {
public:
    int maxDifference(string s) {
       vector <int> mpp(26, 0);
       int n = s.size();

       for(int i = 0;i<n;i++){
            mpp[s[i]-'a']++;
       }
       int maxiodd = 0;  
       int minieven = s.size();
     
       for (int i = 0;i<26;i++){
        if(mpp[i]%2 == 0 && mpp[i] > 0 ){
            minieven = min(minieven, mpp[i]);
        }
        if(mpp[i]%2 != 0){
            maxiodd = max(maxiodd, mpp[i]);
            
        }
       }
       return maxiodd-minieven;
    }
};