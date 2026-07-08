#define MOD 1000000007
class Solution {
long long helper(vector<int>& nums,int k,const int & n){
    vector<long long>p(n);
    for(int i=0;i<n;i++){
        p[i]=(nums[i]%k ==0 ? nums[i] : -nums[i]);
    }
    long long sum=p[0];
    long long ans=p[0];
    for(int i=1;i<n;i++){
        sum=max(p[i],sum+p[i]);
        ans=max(ans,sum);
    }
    
    return ans;
}
    
public:
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st={2};
        for(int num:nums){
            for(int i=2;i*i<=num;i++){
                if(num%i==0){
                    st.insert(i);
                    while(num>0 && num%i==0){
                        num/=i;
                    }
                }
            }
            if(num>1)st.insert(num);
        }
        
        long long ans=LLONG_MIN;
        int bestK=-1;
        
        for(int i:st){
            long long diff=helper(nums,i,n);
            if(diff>ans){
                ans=diff;
                bestK=i;
            }
            else if(diff==ans){
                bestK=min(bestK,i);
            }
        }
        
        return (int) ((((ans%MOD)*bestK)%MOD)+MOD )%MOD;
    }
};