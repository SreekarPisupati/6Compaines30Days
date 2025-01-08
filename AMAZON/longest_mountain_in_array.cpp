// https://leetcode.com/problems/longest-mountain-in-array/submissions/1502053643/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;

    vector<int> dp1(n, 0); 
    vector<int> dp2(n, 0); 
    int maxi = 0;

   
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            dp1[i] = dp1[i - 1] + 1;
        }
    }

   
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            dp2[i] = dp2[i + 1] + 1;
        }
    }

   
    for (int i = 1; i < n - 1; i++) {
        if (dp1[i] > 0 && dp2[i] > 0) { 
            maxi = max(maxi, dp1[i] + dp2[i] + 1);
        }
    }

    return maxi;
}

};