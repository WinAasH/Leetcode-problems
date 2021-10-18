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
private:
    int depth(TreeNode *curr, int target, int deep){
        if(!curr){
            return 0;
        }
        
        if(curr->val == target){
            return deep;
        }
        
        int d1= depth(curr->left, target, deep+1);
        int d2= depth(curr->right, target, deep+1);
        
        return ((d1>d2)? d1: d2);
    }
    
    bool areSiblings(TreeNode *curr, int x, int y){
        if(!curr){
            return false;
        }
        
        if(!curr->left){
            if(!curr->right){
                return false;
            }
            return areSiblings(curr->right, x, y);
        }
        
        if(!curr->right){
            if(!curr->left){
                return false;
            }
            return areSiblings(curr->left, x, y);
        }
        
        if(curr->left->val==x  &&  curr->right->val==y){
            return true;
        }
        
        if(curr->right->val==x  &&  curr->left->val==y){
            return true;
        }
        
        return (areSiblings(curr->left, x, y)  ||  areSiblings(curr->right, x, y));
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int dx= depth(root, x, 0);
        int dy= depth(root, y, 0);
        if(dx!=dy){
            return false;   
        }
        return !areSiblings(root, x, y);
    }
};