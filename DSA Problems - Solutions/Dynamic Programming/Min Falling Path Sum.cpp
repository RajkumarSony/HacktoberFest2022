class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m;
        if(n) m=matrix[0].size();
        int a[n][m];        
        int i,j;
        for(i=0;i<m;i++)    a[0][i]=matrix[0][i];
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(j==0) a[i][j]=matrix[i][j]+min(a[i-1][j],a[i-1][j+1]);
                else if(j==m-1) a[i][j]=matrix[i][j]+min(a[i-1][j],a[i-1][j-1]);
                else{
                    a[i][j]=min( min(a[i-1][j-1] , a[i-1][j]) , a[i-1][j+1]);
                        a[i][j]+=matrix[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(i=0;i<m;i++)
        {
            ans=min(ans,a[n-1][i]);
        }
        return ans;
    }
};
