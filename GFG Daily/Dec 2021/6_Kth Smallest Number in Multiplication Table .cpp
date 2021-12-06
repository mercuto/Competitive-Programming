// ques: https://practice.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

class Solution {
public:
    int KthSmallest(int m, int n, int k) {
        int l = 1, r = m*n;
        int ans = -1;
        while(l<=r) {
            int md = l+(r-l)/2;
            int cnt = 0;
            for(int i=1;i<=n;i++) {
                cnt += min(m, md/i);
            }
            if(cnt>=k) {
                r = md-1;
                ans = md;
            } else {
                l = md + 1;
            }
        }
        return ans;
    }
};