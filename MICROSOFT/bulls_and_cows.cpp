// https://leetcode.com/problems/bulls-and-cows/submissions/1495840116/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int cows=0;
        int bulls=0;
        string ans;
       

       unordered_map<int,int>mp1;
       unordered_map<int,int>mp2;

       for(int i=0;i<n;i++){
        if(secret[i]==guess[i]){
            bulls++;
        }
       }
       for(int i=0;i<n;i++){
        if(secret[i]!=guess[i]){
        mp1[secret[i]]++;
        mp2[guess[i]]++;
        }
       }

       for(auto it:mp1){
        if(mp2.find(it.first)!=mp2.end()){
            cows+= min(it.second , mp2[it.first]);
        }
       }
        string cow = to_string(cows);
        string bull = to_string(bulls);
        ans = bull+'A'+cow+'B';

        return ans;
    }
};