class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& dungeon){
        if(i==m-1 && j==n-1) return max(1,1-dungeon[i][j]);
        
        if(i>=m || j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int a = solve(i+1,j,dungeon);
        int b  = solve(i,j+1,dungeon);
        int health =  min(a,b) - dungeon[i][j];
        if(health <= 0) return dp[i][j] = 1;
        return dp[i][j] = health;
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};
