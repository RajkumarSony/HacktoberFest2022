/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // we are using level order traversal for serializing the binary tree.
        // the different is just that we are storing some unique character for NULL to identify the NULL node.
        //And also even if left and right nodes are null we are pushing them back to the queue to ensure proper string should get generated along with NULL nodes.
        string s="";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else {
                s.append(to_string(node->val)+',');
            }
            if(node != NULL) {
                //push left and right nodes
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //For deserialize we are paralley working with queue and string to create binary tree.
        //here we are using stringstream to avoid for loops and accordingly by our need fetch the next character in string one by one as it needs
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        //First character will always be the root Node 
        TreeNode* root = new TreeNode(stoi(str));
        //Now making queue for generating tree.
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            
            //for left Node
            if(str == "#") {
                node->left = NULL;
            }else {
                //store the left node.
                // by creating left node
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            //for right Node
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));