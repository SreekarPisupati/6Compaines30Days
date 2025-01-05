// https://leetcode.com/problems/shopping-offers/submissions/1498810157/

class Solution {
public:

    map<vector<int>,int>mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp.count(needs)!=0){
            return mp[needs];
        }
        
         int ans=0;
         int n = price.size();
         vector<int>dp(n+1,-1);
         for(int i=0;i<n;i++){
            ans+= needs[i]*price[i];
         } 
         
        for(int i=0;i<special.size();i++){
            bool isValidoffer=true;
            for(int j=0;j<needs.size();j++){
                if(special[i][j]>needs[j]){
                    isValidoffer = false;
                    break;
                }

            }

            
                if(isValidoffer){
                    for(int j=0;j<needs.size();j++){
                         needs[j]-=special[i][j];
                    }

                    int curr = special[i].back() + shoppingOffers(price,special,needs);
                    ans = min(ans,curr);

                     for(int j=0;j<needs.size();j++){
                         needs[j]+=special[i][j];
                    }
                    
                }

            
         }


        return mp[needs]=ans;
    }
};