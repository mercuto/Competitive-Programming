// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
void inorder(Node *root, int lev, vector<int> &leftViewElements) {
    if(!root)
        return;
        
    if(lev>leftViewElements.size())
        leftViewElements.push_back(root->data);
    
    inorder(root->left, lev+1, leftViewElements);
    inorder(root->right, lev+1, leftViewElements);
}

vector<int> leftView(Node *root)
{
    vector<int> leftViewElements;
    inorder(root, 1, leftViewElements);
    return leftViewElements;
}
