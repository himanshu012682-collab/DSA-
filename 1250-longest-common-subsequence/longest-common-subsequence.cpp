class Solution {
public:

int solTab(string s1,string s2,int m,int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

        
        
        
            int solMem(string s1, string s2, int m, int n,
               vector<vector<int>>& dp) {

        if (m == 0 || n == 0) {
            return 0;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s1[m - 1] == s2[n - 1]) {
            dp[m][n] = 1 + solMem(s1, s2, m - 1, n - 1, dp);
        }
        else {
            dp[m][n] = max(
                solMem(s1, s2, m - 1, n, dp),
                solMem(s1, s2, m, n - 1, dp)
            );
        }

        return dp[m][n];
    }
    int rec(string s1,string s2,int m,int n){
        if(m==0||n==0){
            return 0;
        }
        if(s1[m-1]==s2[n-1]){
            return 1+rec(s1,s2,m-1,n-1);
        }
        return max(rec(s1,s2,m-1,n),rec(s1,s2,m-1,n-1));
        
        
            }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       // return rec(text1,text2,m,n);
      // return solMem(text1,text2,m,n,dp);
      return solTab(text1,text2,m,n);
        
    }
};