// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0;i<arr.size();i++){
            
            
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
         if(i>=k-1){
             ans.push_back(arr[dq.front()]);
         }   
        }
        
        return ans;
    }
};