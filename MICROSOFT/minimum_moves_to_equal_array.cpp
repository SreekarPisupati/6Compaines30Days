// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/1494650403/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int n = nums.size();
      int l =0;
      int r = n-1;
        int ans=0;
        while(l<r){
            ans+=(nums[r]-nums[l]);
            r--;
            l++;
        }
        return ans;
        }   
};