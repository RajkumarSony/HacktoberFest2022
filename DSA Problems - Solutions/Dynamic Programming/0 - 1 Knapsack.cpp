#include <bits/stdc++.h>
using namespace std;
 
#define loop1(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
 
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> h(n),s(n);
    int a;
    loop1(i,n) {
        cin>>a;
        h[i]=a;
    }
    loop1(i,n) {
        cin>>a;
        s[i]=a;
    }
    
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    for(int i=h[0];i<=x;i++) dp[0][i] = s[0];
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<=x;j++ ){
            int nottake=dp[i-1][j];
            int take= -1;
            if(h[i] <= j) {
                take=s[i] + dp[i-1][j-h[i]];
            }
            dp[i][j]=max(take,nottake);
        }
    }
    cout<<dp[n-1][x]<<" ";
    return 0;
}
