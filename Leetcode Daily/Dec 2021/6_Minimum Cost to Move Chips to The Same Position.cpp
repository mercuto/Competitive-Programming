//ques : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0, evenCount = 0;
        for(auto it:position)
            if(it%2)
                oddCount++;
            else 
                evenCount++;
        return min(oddCount, evenCount);
    }
};