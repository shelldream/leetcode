/**
	Path Sum
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
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
        inorder_root_index++; //查找根节点在后序数组中的下标
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
    bool hasPathSum(TreeNode* root, int sum) {
        return traverse(root, sum);
    }
    bool traverse(TreeNode* root, int left_sum)
    {
        if(!root)
            if(left_sum != 0)
                return false;
            else
                return true;
        else
        {
            if(traverse(root->left, left_sum-root->val))
                return true;
            if(traverse(root->right, left_sum-root->val))
                return true;
            return false;
        }
    }
};

int main()
{
    int data1[] = {5,4,11,7,2,8,13,4,1};
    int data2[] = {7,11,2,4,5,13,8,4,1};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    Solution test;
    cout<<test.hasPathSum(root,22)<<endl;
    cout<<test.hasPathSum(root,2)<<endl;
    cout<<test.hasPathSum(root,18)<<endl;
}
