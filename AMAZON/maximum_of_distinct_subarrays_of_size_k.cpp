// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/1502167894/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
   long long maxi = 0;
    int n = nums.size();

    unordered_map<int, int> freq;
    long long current_sum = 0;

    int l=0;
    for (int r = 0; r < n; r++) {
        freq[nums[r]]++;
        current_sum += nums[r];

        if (r - l + 1 == k) { 
            if (freq.size() == k) { 
                maxi = max(maxi, current_sum);
            }

            
            freq[nums[l]]--;
            if (freq[nums[l]] == 0) {
                freq.erase(nums[l]);
            }
            current_sum -= nums[l];
            l++;
        }
    }

    return maxi;
    }
};