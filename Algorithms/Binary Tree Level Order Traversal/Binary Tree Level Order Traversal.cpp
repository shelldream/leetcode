/**
	Binary Tree Level Order Traversal
	Author:Xiaojun Huang
	Date:2015-08-09

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildFunc(vector<int>& preorder, int i, int j, vector<int>& inorder, int x, int y)
{
    if(i > j || x > y || i<0 || j<0 || x<0 || y <0 || i>=preorder.size() || j>=preorder.size() || x>=inorder.size() || y>=inorder.size())
        return NULL;
    int root_val = preorder[i];
    TreeNode* root = new TreeNode(root_val);
    int inorder_root_index = x;
    while(inorder[inorder_root_index] != root_val)
        inorder_root_index++;
    int left_tree_node_count = inorder_root_index-x;
    int right_tree_node_count = y-inorder_root_index;
    root->left = buildFunc(preorder, i+1, i+left_tree_node_count, inorder, x, x+left_tree_node_count-1);
    root->right = buildFunc(preorder, i+left_tree_node_count+1, j, inorder, inorder_root_index+1, y);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j = preorder.size()-1;
        int y = inorder.size()-1;
        return buildFunc(preorder, 0, j, inorder, 0, y);
    }

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> NodeQueue;
        vector<vector<int> > ans;
        if(!root)
            return ans;
        NodeQueue.push(root);
        LevelTraverse(ans,NodeQueue);
        return ans;
    }
    void LevelTraverse(vector<vector<int> >& ans, queue<TreeNode*>& NodeQueue)
    {
        vector<int> tmp;
        queue<TreeNode*> nextLevel;
        while(!NodeQueue.empty())
        {
            TreeNode* top_node = NodeQueue.front();
            NodeQueue.pop();
            tmp.push_back(top_node->val);
            if(top_node->left)
                nextLevel.push(top_node->left);
            if(top_node->right)
                nextLevel.push(top_node->right);
        }
        ans.push_back(tmp);
        if(!nextLevel.empty())
            LevelTraverse(ans,nextLevel);
    }
};


int main()
{
    int data1[] = {5,3,2,1,4,8,7,6,9,10};
    int data2[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    Solution solution;
    vector<vector<int> > ans = solution.levelOrder(root);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

