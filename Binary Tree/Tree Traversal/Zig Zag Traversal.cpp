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
--------------------------------------------------------------------------------------------------
    
    
    
//Using Level order traversal
//The same idea can be extended to zig-zag traversal. The only difference would be, if we are on an even level (say second level)** insert into the vector from end. Odd levels insert from beginning.**
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if (!root) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> out;
            
        q.push(root);  
        int level = 0; /* to alternate levels, or a bool variable */
        
        while (!q.empty()) {
            
            int sz = q.size();  
            vector<int> curr(sz); 
            
            for (int i = 0; i < sz; i++) {
                
                TreeNode* tmp = q.front();
                q.pop();
                
                if (level == 0) {
                    curr[i] = tmp->val; // odd level, insert like 0, 1, 2, 3 etc. 
                } else {
                    curr[sz - i - 1] = tmp->val; /* even level insert from end. 3, 2, 1, 0. (sz - i - 1) to get the index from end */
                }
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            out.push_back(curr); // now push the level traversed to output vector
            level = !level; // toggle the level using negation. or level == 0 ? level = 1 : level = 0;
        }
        return out;
    
}

//t.C-O(N)
//S.C-O(N)
