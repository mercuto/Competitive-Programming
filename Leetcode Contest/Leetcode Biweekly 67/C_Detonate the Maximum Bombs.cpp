// https://leetcode.com/contest/biweekly-contest-67/problems/detonate-the-maximum-bombs/
class Solution {
public:
    
    int dfs(int x, vector<vector<int>> &adj, vector<int> &vis) {
        if(vis[x])
            return 0;
        vis[x] = 1;
        int cnt = 0;
        for(auto it:adj[x]) {
            cnt += dfs(it, adj, vis);
        }
        return 1+cnt;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        long long n = bombs.size();
        
        vector<vector<int>> adj(n, vector<int>());
        
        for(int i=0;i<n;i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for(int j=i+1;j<n;j++) {
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long r2 = bombs[j][2];
                long long dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                if(r1*r1>=dist)
                    adj[i].push_back(j);
                if(r2*r2>=dist)
                    adj[j].push_back(i);
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            vector<int> vis(n, 0);
            ans = max(ans, dfs(i, adj, vis));
        }
        return ans;
    }
};