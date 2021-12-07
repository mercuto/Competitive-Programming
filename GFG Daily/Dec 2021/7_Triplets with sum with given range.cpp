//https://practice.geeksforgeeks.org/problems/triplets-with-sum-with-given-range/1#
class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        int triplets = 0;
        sort(Arr, Arr+N);
        for(int it1=0;it1<N-2;it1++) {
            for(int it2=it1+2;it2<N;it2++) {
                int left = it1+1, right = it2-1;
                int targetLeft = L - (Arr[it1]+Arr[it2]);
                int targetRight = R - (Arr[it1]+Arr[it2]);
                
                if(Arr[it1]+Arr[it2]+Arr[right]<L && Arr[it1]+Arr[it2]+Arr[left]>R)
                    break;
                
                int targetIdLeft = -1;
                int l = left, r = right;
                while(l<=r) {
                    int mid = l + (r-l)/2;
                    if(Arr[mid]<targetLeft)
                        l = mid+1;
                    else 
                        r = mid-1, targetIdLeft = mid;
                }
                
                int targetIdRight = -1;
                l = left, r = right;
                while(l<=r) {
                    int mid = l + (r-l)/2;
                    if(Arr[mid]<=targetRight)
                        l = mid+1, targetIdRight = mid;
                    else 
                        r = mid-1;
                }
                
                if(targetIdLeft!=-1 && targetIdRight!=-1)
                    triplets += targetIdRight - targetIdLeft + 1;
            }
        }
        return triplets;
    }
};