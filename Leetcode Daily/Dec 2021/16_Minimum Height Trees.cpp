// https://leetcode.com/problems/minimum-height-trees/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        queue<int> qu;
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++, degree[it[1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                qu.push(i);
            }
        }
        vector<int> ans;
        while(qu.empty()==false) {
            int sz = qu.size();
            ans.clear();
            // for(auto it : degree) cout<<it<<" "; cout<<endl;
            for(int i = 0; i < sz; i++) {
                int tp = qu.front();
                // cout<<"tp: "<<tp<<endl;
                ans.push_back(tp);
                degree[tp] = 0;
                qu.pop();
                for(auto it : adj[tp]) {
                    degree[it]--;
                    // cout<<"it: "<<it<<" d-1 :"<<degree[it]<<endl;
                    if(degree[it] == 1) {
                        qu.push(it);
                    }
                }
            }
        }
        return ans;
    }
};