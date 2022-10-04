#define ll long long
class Solution {
public:
    
int dp[12][10001];

int getans(int x,int n,vector<int>& c){
    
    if(x==0&&n<0)
        return 0;
        
    if(x!=0&&n<0)
        return 10001;
        
    if(x<0)
        return 10001;
    
    if(dp[n][x]!=-1)
        return dp[n][x];
    
    if(x==0)
        return 0;
        
        
    int s=10001;
    
    s=min(s,1+getans(x-c[n],n,c));
    s=min(s,1+getans(x-c[n],n-1,c));
    s=min(s,getans(x,n-1,c));
    
    
    return dp[n][x]=s;
        
}
    int coinChange(vector<int>& c, int amount) {
        
        int n=c.size();
        for(int i=0;i<12;i++)
            for(int j=0;j<10001;j++) 
                dp[i][j]=-1;
        
            int k=getans(amount,n-1,c);
            if(k<=amount) 
                return k;
            else return -1;
    }
};
