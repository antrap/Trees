//Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};


T.C-O(N)
S.C-O(N)

  //Iterative  
    class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     stack<TreeNode*> s;
    TreeNode* curr=root;
    vector<int> ans;
    while(curr!=NULL && s.empty()==false){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        ans.push_back(curr->val);
        curr=curr->right;
    }
    return ans;
    }
};


//T.C-O(N)
//S.C-O(N)
