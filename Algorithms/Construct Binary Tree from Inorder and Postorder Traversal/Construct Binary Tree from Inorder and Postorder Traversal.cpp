/**
	Construct Binary Tree from Inorder and Postorder Traversal
	Author:Xiaojun Huang
	Date:2015-08-12

*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root) {//打印先序遍历的结果
    if(root !=NULL )
    {
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int nodes_count = inorder.size();
        return iter_build(inorder, 0, nodes_count-1, postorder, 0, nodes_count-1);
    }
    TreeNode* iter_build(vector<int>& inorder, int in_i, int in_j, vector<int>& postorder, int post_i, int post_j)
    {
        if(post_j < post_i || in_j < in_i)
            return NULL;
        int root_val = postorder[post_j];
        int i;
        for(i = in_i;i <= in_j;i++)
            if(inorder[i] == root_val)
                break;
        TreeNode* root = new TreeNode(root_val);
        int left_node_num = i-in_i;
        int right_node_num = in_j-i;
        root->left = iter_build(inorder, in_i, i-1, postorder, post_i, post_i+left_node_num-1);
        root->right = iter_build(inorder, i+1, in_j, postorder, post_j-right_node_num, post_j-1);
        return root;
    }
};


int main()
{
    int data1[] = {1,2,4,5,6,7,3,8,9,10};
    int data2[] = {5,4,6,7,2,1,8,3,10,9};
    int data3[] = {5,7,6,4,2,8,10,9,3,1};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    int n3 = sizeof(data3)/sizeof(data3[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    vector<int> postorder(data3, data3+n3);
    Solution solution;
    TreeNode* root = solution.buildTree(inorder,postorder);
    preorderTraversal(root);
}

