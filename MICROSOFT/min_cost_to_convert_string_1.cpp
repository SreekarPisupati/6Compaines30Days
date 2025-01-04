// https://leetcode.com/problems/minimum-cost-to-convert-string-i/submissions/1497013548/

class Solution {

    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
int n = original.size();
int m = source.size();

long long mincost = 0;
vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));


for (int i = 0; i < n; i++) {
    dist[original[i] - 'a'][changed[i] - 'a'] =
        min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
}


for (int i = 0; i < 26; i++) {
    dist[i][i] = 0;
}


for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


for (int i = 0; i < m; i++) {
    if (source[i] != target[i]) {
        if (dist[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) {
            return -1;
        }
        mincost += dist[source[i] - 'a'][target[i] - 'a'];
    }
}

return mincost;

    }
};