class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> forw, rev;
        int n = fruits.size();
        int id = -1;
        for(int i=0;i<n;i++) {
            if(fruits[i][0]>=startPos) {
                id = i;
                break;
            }
        }
        if(id==-1)
            fruits.push_back({startPos, 0}), id = n;
        else {
            if(fruits[id][0]!=startPos)
                fruits.insert(fruits.begin()+id, {startPos, 0});
        }
        n = fruits.size();
        // cout<<"pos: "; for(auto it:fruits) cout<<it[0]<<","<<it[1]<<" : "; cout<<endl;
        int r = id, l = id;
        int s1 = 0;
        int s2 = 0;
        for(int i=0;i<=k;i++) {
            if(r<n && fruits[r][0]==startPos+i)
                s1 += fruits[r][1], r++;
            forw.push_back(s1);
            if(l>=0 && fruits[l][0]==startPos-i)
                s2 += fruits[l][1], l--;
            rev.push_back(s2);
        }
        // cout<<"forw: "; for(auto it:forw) cout<<it<<" "; cout<<endl;
        // cout<<"rev: "; for(auto it:rev) cout<<it<<" "; cout<<endl;
        int ans = 0;
        for(int i=0;i<=k;i++) {
            // cout<<"for: "<<i<<" rev: "<<(k-i*2)<<endl;
            if(k-i*2 >=0 ) {
                ans = max(ans, forw[i]+rev[k-i*2]-forw[0]);
                ans = max(ans, rev[i]+forw[k-i*2]-forw[0]);
            }
            else {
                ans = max(ans, forw[i]);
                ans = max(ans, rev[i]);
            }
        }
        return ans;
    }
};