class Solution {
public:
    int f(vector<int>& a, int l,int r, vector<vector<int>>& dp,int asum) {
        if(l>r) return asum;
        if(dp[l][r]!=-1) return dp[l][r];

        bool aturn = (l+r+1)&1 ? false : true ;
        if(aturn) {
            dp[l][r] = max(f(a,l+1,r,dp,asum+a[l]) , f(a,l,r-1,dp,asum+a[r]));
        } 
        else dp[l][r] = max(f(a,l+1,r,dp,asum) , f(a,l,r-1,dp,asum));

        return dp[l][r];
    }
    bool stoneGame(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int sum=0;
        for(auto i : a) sum+=i;
        return sum-2*f(a,0,n-1,dp,0) < 0;
    }
};
