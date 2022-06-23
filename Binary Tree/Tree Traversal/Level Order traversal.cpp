class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
            
            
            if(root==NULL) return {};
       
            vector<vector<int>> ans;
            
            queue<TreeNode*> q;
            
            
            
                    q.push(root);
                    while(q.empty()==false){
                            int size=q.size();
                            vector<int> levels;
                            for(int i=0;i<size;i++){
                                    TreeNode* temp=q.front();
                                    q.pop();
                                    
                                    levels.push_back(temp->val);
                                    
                                    if(temp->left!=NULL) q.push(temp->left);
                                    if(temp->right!=NULL) q.push(temp->right);
                            }
                            
                            ans.push_back(levels);
                    }
            
          return ans;  
    }
};
