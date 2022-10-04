//Hard level Problem easy to understand
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double ans=0.0;
        for(int i=0;i<nums2.size();i++)
        {   
            nums1.push_back(nums2[i]);
        }
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        int mid=nums1.size()/2;
        if(n%2==0)
        { 
            ans = double(nums1[mid]+nums1[mid-1])/2;
        }
        else
            ans=nums1[mid];
        return ans;
    }
};
