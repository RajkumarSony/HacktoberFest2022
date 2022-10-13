// https://leetcode.com/problems/jump-game/
// Difficulty : Medium Level
// 170/170 test cases passed.
// Success Rate = 38.4%

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0;
        for(i = nums.size()-2; i >= 0; i--){
            minjump++;
            if(nums[i] >= minjump)
			    minjump = 0;
        }
        if(minjump == 0) 
		    return true;
        else 
		    return false;
    }
};
//Time complexity : O(n).
//We are iterating through the nums array only once. The length of nums array is n. Thus, time complexity = O(n).

//Space complexity : O(1).
//We are not using any extra memory. Thus, space complexity = *O(1).