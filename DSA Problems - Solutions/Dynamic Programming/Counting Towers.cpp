#include <bits/stdc++.h>
using namespace std;
 
#define loop1(i,n) for(i=0;i<n;i++)
#define mod 1000000007
 
int main()
{
    int t,n;
    cin>>t;
    vector<vector<long>> dp(1000001,vector<long>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<1000001;i++) {
        dp[i][0] = ((4*dp[i-1][0])%mod + dp[i-1][1] )%mod;
        dp[i][1] = ((2*dp[i-1][1])%mod + dp[i-1][0] ) % mod;
    }
    while(t--) {
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod << endl;
    }
    return 0;
}
