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
        if(!root)return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(!curNode)ans+="#,";
            else ans+=to_string(curNode->val)+',';
            if(curNode){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            
            getline(s,str, ',');
            if(str == "#"){
                curNode->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                curNode->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            if(str == "#"){
                curNode->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                curNode->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));