class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        bool zr = false;
        for(auto it:nums)
            if(it==0) zr = true;
        
        vector<vector<int>> lists;
        vector<int> cur;
        for(auto it:nums) {
            if(it!=0)
                cur.push_back(it);
            else {
                if(cur.empty()==false)
                    lists.push_back(cur);
                cur.clear();
            }
        }
        if(cur.empty()==false)
            lists.push_back(cur);
        
        int ans = INT_MIN;
        
        for(auto list:lists) {
            int n1 = list.size();
            int mnNeg = 1;
            int id = 0;
            for(auto it:list) {
                mnNeg *= it;
                if(mnNeg<0)
                    break;
                id++;
            }
            
            if(mnNeg>0) {
                ans = max(ans, mnNeg);
                continue;
            }
            
            int cur = 1;
            int id2 = 0;
            for(auto it:list) {
                cur *= it;
                if(cur<0 && id!=id2)
                    ans = max(ans, cur/mnNeg);
                else 
                    ans = max(ans, cur);
                id2++;
            }
        }
        
        return ans<0 ? (zr ? 0 : ans) : ans;
    }
};