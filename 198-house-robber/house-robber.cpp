class Solution {
public:
int pro(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int in=nums[i]+pro(nums,i+2,n,dp);
        int ex=0+pro(nums,i+1,n,dp);
        dp[i]=max(in,ex);
        return dp[i];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>dp(n+1,-1);
        return pro(nums,i,n,dp);

        
    }
};