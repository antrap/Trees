//Using Two stacks
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            
            if(root==NULL)
                    return {};
         
       vector<vector<int>> res;
            stack<TreeNode*> s1;
            stack<TreeNode*> s2;
            s1.push(root);
            while(s1.empty()==false || s2.empty()==false){
                    vector<int> ans1;
                    while(s1.empty()==false){
                            TreeNode* curr=s1.top();
                            s1.pop();
                            ans1.push_back(curr->val);
                            if(curr->left!=NULL)
                                    s2.push(curr->left);
                            if(curr->right!=NULL)
                                    s2.push(curr->right);
                            
                    }
                    res.push_back(ans1);
                    if(s2.empty()==true)
                        return res;
                    
                    vector<int> ans2;
                     while(s2.empty()==false){
                            TreeNode* curr=s2.top();
                            s2.pop();
                            ans2.push_back(curr->val);
                            if(curr->right!=NULL)
                                    s1.push(curr->right);
                            if(curr->left!=NULL)
                                    s1.push(curr->left);
                           
                            
                    }
                    res.push_back(ans2);
                    
            }
            
            return res;
        
    }
};


//T.C-O(n)
//S.C-O(N)
