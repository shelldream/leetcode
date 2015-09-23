/**
	Flatten Binary Tree to Linked List
	Author:Xiaojun Huang
	Date:2015-09-23

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

void traverse(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<"  ";
        traverse(root->left);
        traverse(root->right);
    }
}
class Solution {
public:
    void flatten(TreeNode* root) {
        root = flatten_tree(root);
    }
    TreeNode* flatten_tree(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode* left_subtree = flatten_tree(root->left);
        TreeNode* right_subtree = flatten_tree(root->right);
        if(!left_subtree)
            return root;
        TreeNode* p = left_subtree;
        while(p->right)
            p = p->right;
        p->right = right_subtree;
        root->left = NULL;
        root->right = left_subtree;
        return root;
    }
};
int main()
{
    int preorder[] = {1,2,3,4,5,6};
    int inorder[] = {3,4,2,6,5,1};
    int n1 = sizeof(preorder)/sizeof(preorder[0]);
    int n2 = sizeof(inorder)/sizeof(inorder[0]);
    vector<int> nums1(preorder,preorder+n1);
    vector<int> nums2(inorder,inorder+n2);
    TreeNode* root = buildTree(nums1,nums2);
    Solution test;
    test.flatten(root);
    traverse(root);
}

