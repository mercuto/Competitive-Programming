class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    qu.push({i,j});
                }
            }
        }
        
        int ans = 0;
        while(qu.empty()==false) {
            int sz = qu.size();
            // cout<<"sz: "<<sz<<endl;
            bool found = false;
            for(int i=0;i<sz;i++) {
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==0 || grid[x][y]==3)
                    continue;
                found = true;
                // cout<<x<<" "<<y<<endl;
                grid[x][y] = 3;
                qu.push({x,y-1});
                qu.push({x,y+1});
                qu.push({x-1,y});
                qu.push({x+1,y});
            }
            if(found)
                ans++;
            // cout<<"ans: "<<ans<<endl;
        }
        
        bool ans1 = true;
        for(auto it:grid)
            for(auto jt:it)
                if(jt==1)
                    ans1 = false;
                    
        return ans1 ? ans-1 : -1;
    }
};