class Solution {
  public:
    int Modulo(int a, string b)
    {
        int mod = 0;
        for (int i = 0; i < b.size(); i++)
            mod = (mod * 10 + b[i] - '0') % a;
        return mod; 
    }
        
    
    int getLastDigit(string a, string b) {
        int len_a = a.size(), len_b = b.size();
        if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0')
            return 1;
        if (len_b == 1 && b[0] == '0')
            return 1;
        if (len_a == 1 && a[0] == '0')
            return 0;
        int exp = (Modulo(4, b) == 0) ? 4 : Modulo(4, b);
        int res = pow(a[len_a - 1] - '0', exp);
        return res % 10;
    }
};