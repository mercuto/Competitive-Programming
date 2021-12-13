// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                if(j-nums[i-1]>=0 && dp[i-1][j-nums[i-1]]==1)
                    dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][sum])
            return true;
        return false;
    }
};