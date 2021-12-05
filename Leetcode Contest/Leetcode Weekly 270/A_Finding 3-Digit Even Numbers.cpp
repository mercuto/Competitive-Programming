// Ques: https://leetcode.com/problems/finding-3-digit-even-numbers/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int a, b, c;
        set<int> vec;
        int n = digits.size();
        for(int i=0;i<n;i++) {
            if(digits[i]!=0) {
                a = digits[i];
                for(int j=0;j<n;j++) {
                    if(j!=i) {
                        b = digits[j];
                        for(int k=0;k<n;k++) {
                            if(k!=i && k!=j)  {
                                c = digits[k];
                                if(c%2==0) {
                                    vec.insert(a*100+b*10+c);
                                }
                            }
                        }
                    } 
                }
            }
        }
        vector<int> ans;
        for(auto it:vec)
            ans.push_back(it);
        return ans;
    }
};