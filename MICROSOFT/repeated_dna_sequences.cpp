// https://leetcode.com/problems/repeated-dna-sequences/submissions/1496392053/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n = s.size();
        int l=0;
        int r=9;
        unordered_map<string,int>mp;
        mp[s.substr(0,10)]=1;

        while(r<n){
           l++;
           r++;

            if(mp.find(s.substr(l,r-l+1))!=mp.end()){
                mp[s.substr(l,r-l+1)]++;

            }
            else{
                mp[s.substr(l,r-l+1)]=1;
            }
        }

        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
            
        }

        return ans;
    }
};