class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
            
         return isMirror(root->left,root->right);
    }
        
        
        bool isMirror(TreeNode* p,TreeNode* q){
                if(p==NULL && q==NULL) return true;
                if(p==NULL || q==NULL) return false;
                
                return (p->val==q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);
        }
};
