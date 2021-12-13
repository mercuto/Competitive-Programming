class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int i = 0, j = n-1;
        int ans = 0;
        int c1 = capacityA, c2 = capacityB;
        while(i<=j) {
            if(i==j) {
                if(max(c1, c2)<plants[i]) {
                    ans++;
                }
                break;
            }
            if(c1<plants[i]) 
                c1 = capacityA, ans++;
            c1 -= plants[i];
            i++;
            if(c2<plants[j])
                c2 = capacityB, ans++;
            c2 -= plants[j];
            j--;
        }
        return ans;
    }
};