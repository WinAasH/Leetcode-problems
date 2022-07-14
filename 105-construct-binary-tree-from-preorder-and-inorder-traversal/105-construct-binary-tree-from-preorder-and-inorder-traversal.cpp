class Solution {
public:
    TreeNode* helperTree(vector<int> &in,vector<int> &pre,int inS,int inE,int preS,int preE){
    //empty base case
    if(inS > inE){
        return NULL;
    }
    int rootData = pre[preS];
    int rootindex = -1;
    for(int i=inS; i<=inE; ++i){
        if(in[i] == rootData){
            rootindex = i;
        	break;
        }
    }
    //some variables
    int linS = inS;
    int linE = rootindex-1;
    int lpreS = preS+1;
    int lpreE = linE-linS+lpreS;
  
    int rpreS = lpreE+1;
    int rpreE = preE;
    int rinS = rootindex+1;
    int rinE = inE;
    
    TreeNode* root = new TreeNode(rootData);
    root->left = helperTree(in,pre,linS,linE,lpreS,lpreE);
    root->right = helperTree(in,pre,rinS,rinE,rpreS,rpreE);
    return root;
    
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inLength = inorder.size();
        int preLength = preorder.size();
        return helperTree(inorder,preorder,0,inLength-1,0,preLength-1);
    }
};