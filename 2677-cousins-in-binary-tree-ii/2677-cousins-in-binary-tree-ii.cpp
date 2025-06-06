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
//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }        

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()) {
            int n = que.size();
            int nextLevelSum = 0;

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }


                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};
