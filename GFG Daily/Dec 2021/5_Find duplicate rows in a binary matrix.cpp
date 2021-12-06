// ques : https://practice.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1
class Trie{
public:
    Trie *left;
    Trie *right;
    Trie(){
        left = NULL;
        right = NULL;
    }
};
class Solution
{   
public:
    vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
    { 
        // Your code here    
        vector<int> res;
        Trie *head = new Trie();
        for(int i=0;i<M;i++){
            Trie *temp = head;
            bool isDuplicate = true;
            for(int j=0;j<N;j++){
                if(matrix[i][j]==0){
                    if(!temp->left){
                        isDuplicate = false;
                        temp->left = new Trie();
                    }
                    temp = temp->left;
                }
                else{
                    if(!temp->right){
                        isDuplicate = false;
                        temp->right = new Trie();
                    }
                    temp = temp->right;
                }
            }
            if(isDuplicate){
               res.push_back(i); 
            }
        }
        return res;
    } 
};