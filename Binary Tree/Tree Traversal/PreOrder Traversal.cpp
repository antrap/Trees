//Recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
private:
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        nodes.push_back(root -> val);
        preorder(root -> left, nodes);
        preorder(root -> right, nodes);
    }
};


//T.C-O(N)
//S.C-O(N)
  
  
  //Iterative
  class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
            
            if(root==NULL) return {};
        vector<int> ans;
            stack<TreeNode*> s;
            
            s.push(root);
            while(s.empty()==false){
                    TreeNode* temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    
                    if(temp->right!=NULL) s.push(temp->right);
                    if(temp->left!=NULL) s.push(temp->left);
            }
            
            
            return ans;
    }
};


//T.C-O(N)
//S.C-O(N)
