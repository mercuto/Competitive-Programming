// https://practice.geeksforgeeks.org/problems/7a28dab3cd1a41839ca28cc33f05963c2654e9ff/1
const int NAX = 1e5+2;
int power[NAX];

class Solution{
    public:
    const int prime = 93;//avoids collisions during hash
    const int mod = 1e9+7;//also avoids collision during hash
    int hash(char ch,int idx){
        //(int)ch -> 0-256
        return ((int64_t)ch*power[idx+1])%mod;
    }
    string solve(string s,int HA[]){
        int n = (int)s.length()/2;
        for(int i=n; i>0; i--){
            int hashLeft = (HA[i-1]-HA[0]+hash(s[0],0))%mod;
            int hashRight = (HA[2*i-1]-HA[i]+hash(s[i],i))%mod;
            hashLeft = ((int64_t)1 * hashLeft * power[i]) % mod;
            if(hashLeft < 0){
                hashLeft += mod;
            }
            if(hashRight < 0){
                hashRight += mod;
            }
            if(hashLeft == hashRight){
                string answer = solve(s.substr(0,i),HA);
                answer += "*";
                for(int j=2*i; j<(int)s.length(); j++){
                    answer += s[j];
                }
                return answer;//smallest is possible when larger substring is mathched, so return first matched gives our anser
            }
        }
        return s;//no match
    }
    string compress(string s)
    {
        // Your code goes here
        int64_t p = 1;
        for(int i=0; i<NAX; i++){
            power[i] = p;
            p = (p*prime)%mod;
        }
        int HA[(int)s.length()];
        HA[0] = hash(s[0],0);
        for(int i=1; i<(int)s.length(); i++){
            HA[i] = ((int64_t)0+HA[i-1]+hash(s[i],i))%mod;
        }
        return solve(s,HA);
    }
    
};