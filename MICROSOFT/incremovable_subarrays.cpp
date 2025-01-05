// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/submissions/1498809588/

class Solution {
public:
    long long countSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    long long result = 0;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result += (n2 - j);
            i++;
        } else {
            j++;
        }
    }

    return result;
}

long long incremovableSubarrayCount(vector<int>& a) {
    long long n = a.size();
    if (n == 1)
        return 1;

    int i = 0, j = n - 1;
    vector<int> arr1, arr2;

    while ((i + 1) < n && a[i] < a[i + 1]) {
        arr1.push_back(a[i]);
        i++;
    }
    arr1.push_back(a[i]);

    while ((j - 1) >= 0 && a[j] > a[j - 1]) {
        arr2.push_back(a[j--]);
    }
    arr2.push_back(a[j]);

    reverse(arr2.begin(), arr2.end());

    if (j < i) {
        long long ans = (1LL * n * (n + 1)) / 2;
        return ans;
    }

    long long ans = 0;
    ans += arr1.size();
    ans += arr2.size();
    ans += countSortedArrays(arr1, arr2);
    ans++;

    return ans;
}
};