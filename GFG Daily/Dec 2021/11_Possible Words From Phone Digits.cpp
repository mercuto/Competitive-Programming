// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> keyMapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> dfs(int idx, int ar[], int n) {
        if(idx>=n)
            return {""};
        vector<string> possibleWords = dfs(idx+1, ar, n);
        vector<string> newPossibleWords;
        for(auto word:possibleWords) {
            for(auto ch:keyMapping[ar[idx]]) {
                string curWord = word;
                curWord += ch;
                newPossibleWords.push_back(curWord);
            }
        }
        return newPossibleWords;
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> possibleWords = dfs(0, a, N);
        for(auto &word:possibleWords)
            reverse(word.begin(), word.end());
        sort(possibleWords.begin(), possibleWords.end());
        return possibleWords;
    }
};