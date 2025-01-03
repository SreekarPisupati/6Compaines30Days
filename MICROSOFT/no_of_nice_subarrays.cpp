// https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1495930298/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int l = 0, r = 0;
    int n = nums.size();
    int oddcnt = 0, nice = 0, nice_upto_r = 0;

    while (r < n) {
        
        if (nums[r] % 2 != 0) {
            oddcnt++;
            nice_upto_r = 0; 
        }

     
        while (oddcnt == k) {
         
            nice_upto_r++;
            if (nums[l] % 2 != 0) {
                oddcnt--;
            }
            l++;
        }

       
        nice += nice_upto_r;
        r++;
    }

    return nice;
    }
};