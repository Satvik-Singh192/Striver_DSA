#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

/*APPROACH
i created a map to store pair of column coordinates and vector of element present at that column coordinate.
i needed to store pair in the vector too because i cant simply sort all the values of node in same columns,
the node should be sorted depth wise first then for the nodes of same depth,they must be sorted value wise.

then i simply iterated over the map and sorted the vector as required and stored the values in temporary vector and added the 
vector to final vector<vector<int>>
*/
class Solution {
    map<int,vector<pair<int,int>>> m;
    void recursion(TreeNode* root,int col,int row){
        if(root==NULL)return;
        m[col].push_back(make_pair(row,root->val));
        if(root->left!=NULL)
        recursion(root->left,col-1,row+1);
        if(root->right!=NULL)
        recursion(root->right,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> bruh;
        recursion(root,0,0);
        for(auto it=m.begin();it!=m.end();it++){
            sort(it->second.begin(),it->second.end());
            bruh.clear();
            for(int i=0;i<it->second.size();i++){
                bruh.push_back(it->second[i].second);
            }
            ans.push_back(bruh);
        }
        return ans;
    }
};