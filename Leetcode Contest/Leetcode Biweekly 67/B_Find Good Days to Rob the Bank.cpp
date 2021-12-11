// https://leetcode.com/contest/biweekly-contest-67/problems/find-good-days-to-rob-the-bank/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& ar, int time) {
        int n = ar.size();
        vector<int> ps1(n), ps2(n);    
        ps1[0] = 0;
        for(int i=1;i<n;i++) {
            if(ar[i]<=ar[i-1])
                ps1[i] = 1+ps1[i-1];
            else 
                ps1[i] = 0;
        }
        ps2[n-1] = 0;
        for(int i=n-2;i>=0;i--) {
            if(ar[i]<=ar[i+1])
                ps2[i] = 1+ps2[i+1];
            else
                ps2[i] = 0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(ps1[i]>=time && ps2[i]>=time)
                ans.push_back(i);
        }
        return ans;
    }
};