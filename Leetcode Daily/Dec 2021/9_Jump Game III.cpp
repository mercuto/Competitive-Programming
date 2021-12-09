// https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    
    void dfs(int start, vector<int> &arr, vector<int> &vis, bool &ans) {
        if(start<0 || start>=arr.size())
            return;
        if(arr[start]==0){
            ans = true;
            return;
        }
        
        if(vis[start])
            return;
        vis[start] = 1;
        dfs(arr[start]+start, arr, vis, ans);
        dfs(start-arr[start], arr, vis, ans);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        bool ans = false;
        dfs(start, arr, vis, ans);
        return ans;
    }
};