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
    
    //This function is used to create index mapping for inorder array to get the element present at that position.
    void createMapping(vector<int>& inorder, map<int,int>& nodeToIndex, int size) {
        for(int i = 0; i < size; i++) {
            nodeToIndex[inorder[i]]=i;
        }
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int,int>& nodeToIndex) {
        //base case;
        if(index < 0 || inOrderStart > inOrderEnd) return NULL;
        //take the root node
        //as we are travelling from rightmost side of the postOrder array
        int element = postorder[index--];
        //take the root node
        TreeNode* root = new TreeNode(element);
        //now find the position of this root node in subtree from inorder tree.
        int position = nodeToIndex[element];
        //Now recursive calls for left subtree and right subtrees
        //Here first of all in case of postorder + inorder --> we have to call right node of the binary tree as in postorder array we are traversing from right side having right node after the root node and then left node
        //In case of inorder + preorder --> call left and right node 
        root->right = build(inorder, postorder, index, position+1, inOrderEnd, n, nodeToIndex);
        root->left = build(inorder, postorder, index, inOrderStart, position-1, n, nodeToIndex);
        return root;   
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          // This is index of initial root
        int n = inorder.size();
        int postOrderIndex = n - 1;
        //create map to store 
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans = build(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};