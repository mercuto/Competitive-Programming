class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int cnt = 0;
        for(int i=0;i<n;i++)
            if(arr[i]<=k)
                cnt++;
        
        int cur = 0;
        for(int i=0;i<cnt;i++)
            if(arr[i]<=k)
                cur++;
        
        int ans = cnt-cur;
        for(int i=cnt;i<n;i++) {
            if(arr[i-cnt]<=k)
                cur--;
            if(arr[i]<=k)
                cur++;
            ans = min(ans, cnt-cur);
        }
        return ans;
    }        
};