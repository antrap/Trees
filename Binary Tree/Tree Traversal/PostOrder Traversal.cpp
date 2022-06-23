//Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         
            if(root==NULL) return {};
        vector<int> ans;
            stack<TreeNode*> s;
            
            s.push(root);
            while(s.empty()==false){
                    TreeNode* temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    
                    if(temp->left!=NULL) s.push(temp->left);
                    if(temp->right!=NULL) s.push(temp->right);
                    
            }
            
            
         reverse(ans.begin(),ans.end());
            
            return ans;
    }
};


//T.C-O(n)
//S.C-O(N)


//Rescursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
    }
};

//T.C-O(n)
//S.C-O(N)
