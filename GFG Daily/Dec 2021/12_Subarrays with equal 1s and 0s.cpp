// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0;i<n;i++)
            if(arr[i]==0)
                arr[i] = -1;
        
        map<long long ,long long > map;
        map[0] = 1;
        long long ans = 0;
        long long sum = 0;
        for(int i=0;i<n;i++) {
            sum += arr[i];
            ans += map[sum];
            map[sum]++;
        }
        return ans;
    }
};