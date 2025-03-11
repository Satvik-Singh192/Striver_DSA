#include<iostream>
#include<vector>
#include<queue>

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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if (root == nullptr) {
                return ans;
            }
    
            int left_to_right = 1;
            queue<TreeNode*> q;
            q.push(root);
    
            while (!q.empty()) {
                int level_size = q.size();
                vector<int> level;
                for (int i = 0; i < level_size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
    
                if (left_to_right == 0) {
                    reverse(level.begin(), level.end());
                }
    
                ans.push_back(level);
                left_to_right = !left_to_right;
            }
    
            return ans;
        }
    };
    