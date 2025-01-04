// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/1496899813/

class Solution {
public:


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int>>> neighbours(n);
    vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
      
      for(auto it:edges){
        distance[it[0]][it[1]] = it[2];
         distance[it[1]][it[0]] = it[2];

      }
    for(int i=0;i<n;i++){
        distance[i][i]=0;
    }

  
        int city_cnt = n;
        int cityno = -1;



        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][k] == INT_MAX  || distance[k][j]==INT_MAX){
                        continue;
                    } 
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(distance[i][j]<=distanceThreshold){
                    cnt++;
                }
            }

            if(cnt<=city_cnt){
                city_cnt=cnt;
                cityno = i;
            }
        }

        return cityno;
}

  
};