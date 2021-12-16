// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int ar[],
                                             long long int n, long long int k) {
    long long i = k-1, j=0;
    vector<long long> ans;
    while(i<n) {
        while(ar[j]>=0 && j<i) 
            j++;
        if(ar[j]<0)
            ans.push_back(ar[j]);
        else
            ans.push_back(0);
        i++;
        j = max(j, i-k+1);
    }
    return ans;
 }