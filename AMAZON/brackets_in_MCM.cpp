// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
    
  public:
  
  
    pair<string,int> f(int i, int j, vector<int>&arr, vector<vector<pair<string,int>>>&dp){
        if(i==j){
            string s ="";
            s+= 'A'+i-1;
            return {s,0};
        }
        
        if(dp[i][j].second!=-1){
            return dp[i][j];
        }
        int mini = 1e9;
        string st = "";
        for(int k=i;k<j;k++){
            
            auto left = f(i,k,arr,dp);
            auto right = f(k+1,j,arr,dp);
            int op = arr[i-1]*arr[k]*arr[j] + left.second + right.second;
            string s = "";
            s+= "(" + left.first + right.first + ")";
            
            if(mini>op){
                mini = op;
                st=s;
            }
    }
    
        return dp[i][j] = {st,mini};
    
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<pair<string,int>>>dp(n, vector<pair<string,int>>(n,{"",-1}));
        auto p =  f(1,n-1,arr,dp);
        return p.first;
    }
};