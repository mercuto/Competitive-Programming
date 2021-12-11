// https://leetcode.com/contest/biweekly-contest-67/problems/find-subsequence-of-length-k-with-the-largest-sum/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        int n = nums.size();
        for(int i=0;i<n;i++)
            vec.push_back({nums[i], i});
        sort(vec.begin(), vec.end());
        vector<int> ans(n, INT_MIN);
        for(int i=n-1;i>n-1-k;i--) {
            ans[vec[i].second] = vec[i].first;
        }
        vector<int> fans;
        for(auto it:ans) {
            if(it!=INT_MIN)
                fans.push_back(it);
        }
        return fans;
    }
};