// https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr, arr+n);
            int ans = INT_MAX;
            int l = 0, r = n-1;
            while(l<r) {
                int sum = arr[l]+arr[r];
                if(abs(sum) < abs(ans)) 
                    ans = sum;
                if(abs(sum)==abs(ans))
                    ans = max(sum, ans);
                if(sum<0)
                    l++;
                else
                    r--;
            }
            return ans;
        }
};