// https://leetcode.com/problems/domino-and-tromino-tiling/
class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        if(n==1) return dp[1];
        dp[2] = 2;
        if(n==2) return dp[2];
        dp[3] = 5;
        if(n==3) return dp[3];
        for(int i=4;i<=n;i++) {
            dp[i] += dp[i-1] + dp[i-2];
            for(int j=i-3;j>=0;j--)
                dp[i] += dp[j]*2;
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};