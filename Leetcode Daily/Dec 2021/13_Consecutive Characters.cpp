// https://leetcode.com/problems/consecutive-characters/
class Solution {
public:
    int maxPower(string s) {
        s += '0';
        int i=0, j=0;
        int ans = 0;
        while(j<s.size()) {
            if(s[i]!=s[j]) {
                ans = max(ans, j-i);
                i = j;
            } 
            j++;
        }
        return ans;
    }
};