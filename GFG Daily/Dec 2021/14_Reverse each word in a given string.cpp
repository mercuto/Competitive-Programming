// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1
class Solution
{
  public:
    string reverseWords (string s)
    {
        s += ".";
        int prv = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='.')
                reverse(s.begin()+prv, s.begin()+i), prv = i+1;
        }
        
        return s.substr(0, s.size()-1);
    }
};
