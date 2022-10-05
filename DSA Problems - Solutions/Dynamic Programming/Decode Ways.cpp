class Solution {
public:
    int f(int ind, string& s, vector<int>& dp) {
        if(s[0] =='0') return 0;
        if
            (ind<0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ans = 0;
        if(s[ind]!= '0') {
            ans = f(ind-1, s,dp);
        }
         if(ind>0 && (s[ind-1] == '1' || (s[ind]<'7' && s[ind-1]=='2') ) ) {
             ans+= f(ind-2,s,dp);
         }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1) ;
        return f(n-1,s,dp);
    }
};
