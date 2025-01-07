// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1501043517/

class Solution {
public:

    int solve(vector<int>&prices, int n, int buy, int ind, int cap ,vector<vector<vector<int>>>&dp ){
        
        if(ind==n || cap==0 ){
            return 0;
        }

        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }

        if(buy){
            return dp[ind][1][cap]=max(-prices[ind] +  solve(prices,n,0,ind+1,cap,dp) , 0+ solve(prices,n,1,ind+1,cap,dp) );
        }
        else{
        return dp[ind][0][cap] = max(prices[ind] + solve(prices,n,1,ind+1,cap-1,dp) , 0+ solve(prices,n,0,ind+1,cap,dp));
        }


    

    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int ind = n-1;ind >=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap =1;cap<=k;cap++){
                     if(buy){
             dp[ind][1][cap]=max(-prices[ind] +  dp[ind+1][0][cap] , 0+ dp[ind+1][1][cap]);
        }
        else{
         dp[ind][0][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0+ dp[ind+1][0][cap]);
        }

                }
            }


        }

    //     int ans = solve(prices,n,1,0,k,dp);
    //     return ans;

        return dp[0][1][k];
    }
};