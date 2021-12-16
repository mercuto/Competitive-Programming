//https://codeforces.com/contest/1618/problem/D
#include<bits/stdc++.h>
using namespace std;

typedef long long int   ll;
#define int             ll
#define PI              3.1415926535897932384626433832795

#ifdef ONLINE_JUDGE
    #define deb   if(false)
#else
    #define deb   if(true)
#endif

#define pb              push_back
#define rep0            for(int i=0;i<n;i++)
#define rep1            for(int i=1;i<=n;i++)
#define inpar(ar,st,en) for(int i=st;i<en;i++)cin>>ar[i];
#define shoar(ar,st,en) for(int i=st;i<en;i++)cout<<ar[i]<<" ";cout<<endl;

#define fastasF_boi()   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl            "\n"
//#define cerr            if(false)cerr

int mod=1000000007;
int maxn=200001;
int binpow(int a,int b,int mod){int res=1;while(b>0){if(b%2){res=(res*a)%mod;b--;}a=(a*a)%mod;b/=2;}return res%mod;}
int binpow(int a,int b){int res=1;while(b>0){if(b%2){res=(res*a);b--;}a=(a*a);b/=2;}return res;}
bool isPrime(int n){if(n==1)return false;for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
int mulmod(int a,int b){return ((a%mod)*(b%mod))%mod;}
int addmod(int a,int b){return (((a%mod)+(b%mod))+mod)%mod;}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    int ans = 0;
    sort(ar.begin(), ar.end());
    int l = n-2*k, r = n-k;
    for(int i=0;i<l;i++)
        ans += ar[i];
    for(int i=0;i<k;i++) {
        ans += (ar[l+i]/ar[r+i]);
    }
    cout<<ans<<endl;
}

// 1 1 1 1 1 2 3 
//   l      r   
signed main(){

    fastasF_boi();
    int t=1;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        deb {
            cout<<"Case #"<<tt<<":"<<endl;
        }
        solve();
    }
}
 