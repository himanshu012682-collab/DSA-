class Solution {
public:
int solve(int amount,vector<int>&coins,int n,vector<vector<int>>&dp){
    if(amount==0){
        return 1;
    }
    if(n==0||amount<0){
        return 0;
    }
    if(dp[n][amount]!=-1){
        return dp[n][amount];
    }
    int in=solve(amount-coins[n-1],coins,n,dp);
    int ex= solve(amount,coins,n-1,dp);
    dp[n][amount]= in+ex;
    return dp[n][amount];

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(amount,coins,n,dp);

        
    }
};