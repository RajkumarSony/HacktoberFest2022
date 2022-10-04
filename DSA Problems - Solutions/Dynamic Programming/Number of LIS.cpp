class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size(),maxi=1;
        
        vector<int> dp(n,1),count(n,1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]>a[j] && dp[i]<dp[j]+1) {
                    count[i]=count[j];
                    dp[i]=dp[j]+1;
                }
                else if(a[i]>a[j] && dp[i]==dp[j]+1) {
                    count[i]+=count[j];
                    dp[i]=dp[j]+1;
                }
            }
                maxi=max(maxi,dp[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++) {
            // cout<<count[i]<<" ";
            if(dp[i]==maxi) ans+=count[i];
        }
        return ans;
    }
};
