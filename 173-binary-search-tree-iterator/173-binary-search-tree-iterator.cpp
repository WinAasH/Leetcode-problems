class BSTIterator {
    
    private:
    stack<TreeNode *>s;
    private:
    void push(TreeNode *root)
    {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode *top=s.top();
        s.pop();
        push(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if(!s.empty())
            return 1;
        return 0;
    }
};