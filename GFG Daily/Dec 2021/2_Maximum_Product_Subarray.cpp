class Solution{
public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n) {
        long long int max_ending_here = arr[0];
        long long int min_ending_here = arr[0];
        long long int max_so_far = arr[0];
        for (int i = 1; i < n; i++)
        {
            long long int temp = max({1ll*arr[i], 1ll*arr[i] * max_ending_here, 1ll*arr[i] * min_ending_here});
            min_ending_here = min({1ll*arr[i], 1ll*arr[i] * max_ending_here, 1ll*arr[i] * min_ending_here});
            max_ending_here = temp;
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};