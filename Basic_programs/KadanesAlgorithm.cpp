#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> arr,int n)
{
    int max_so_far=arr[0],max_ending_here=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<(max_ending_here+arr[i]))
            max_ending_here=max_ending_here+arr[i];
        else
            max_ending_here=arr[i];
        if(max_so_far<max_ending_here)
            max_so_far=max_ending_here;
    }
    return max_so_far;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<maxSubarraySum(v,n)<<endl;
}