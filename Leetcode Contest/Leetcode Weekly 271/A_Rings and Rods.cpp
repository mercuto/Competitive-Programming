class Solution {
public:
    int countPoints(string rings) {
        set<char> set[10];
        for(int i=0;i<rings.size();i+=2) {
            char col = rings[i];
            int num = rings[i+1]-'0';
            set[num].insert(col);
        }
        int cnt = 0;
        for(int i=0;i<10;i++)
            if(set[i].size()==3)
                cnt++;
        return cnt;
    }
};