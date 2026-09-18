class Solution {
public:
int solMem(string s1,string s2,int m,int n,vector<vector<int>>&dp){
     if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s1[m-1]==s2[n-1]){
       dp[m][n]=solMem(s1,s2,m-1,n-1,dp);
    }
    else{
    int insert=solMem(s1,s2,m,n-1,dp);
    int del=solMem(s1,s2,m-1,n,dp);
    int replace=solMem(s1,s2,m-1,n-1,dp);
    dp[m][n]=1+ min(insert,min(del,replace));
    
    }
    return dp[m][n];
}
int rec(string s1,string s2,int m,int n){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(s1[m-1]==s2[n-1]){
        return rec(s1,s2,m-1,n-1);
    }
    int insert=rec(s1,s2,m,n-1);
    int del=rec(s1,s2,m-1,n);
    int replace=rec(s1,s2,m-1,n-1);
    return 1+ min(insert,min(del,replace));
}
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
       // return rec(word1,word2,m,n);
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return solMem(word1,word2,m,n,dp);
        
    }
};