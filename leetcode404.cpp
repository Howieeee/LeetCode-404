/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            
            for(int i=0;i<q.size();i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                    if(node->left->left ==NULL && node->left->right == NULL){
                        sum += node->left->val;
                    }
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }           
        }
        
        return sum;
    }
};
