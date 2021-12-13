class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++) {
            long long mn = 10e10, mx = -1ll*10e10;
            for(int j=i;j<n;j++) {
                mn = min(nums[j]*1ll, mn);
                mx = max(nums[j]*1ll, mx);
                ans += (mx-mn);
            }
        }
        return ans;
    }
};