// https://leetcode.com/problems/wiggle-sort-ii/submissions/1497995104/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted;

        vector<int>count(5001,0);

        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }

        for(int i=0;i<count.size();i++){
            while(count[i]--){
                sorted.push_back(i);
            }
        }

        int left = (n-1)/2;
        int right = n-1;

        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=sorted[left];
                left--;
            }
            else{
                nums[i]=sorted[right];
                right--;
            }
        }

    }
};