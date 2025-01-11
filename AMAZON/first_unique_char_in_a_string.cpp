// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1504901405/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int mini = INT_MAX;
        unordered_map<char,pair<int,int>>mp;

        for(int i=0;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {1,i};
            }
            else{
                mp[s[i]].first++;
            }
        }

        for(auto it:mp){
            if(it.second.first==1){
                mini = min(mini,it.second.second);
            }
        }

        return (mini==INT_MAX)?-1:mini;
    }
};