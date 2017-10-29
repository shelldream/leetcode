/*
 *  二叉树数据结构定义
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
        ,left(NULL)
        ,right(NULL)
    {}
};

TreeNode* buildHelperPreIn(std::vector<int>& preorder, std::vector<int>& inorder, \
    size_t pre_begin, size_t pre_end, size_t in_begin, size_t in_end)
{
    if (pre_begin < 0 || pre_end >= preorder.size() || \
        in_begin < 0 || in_end >= inorder.size() || \
        pre_end < pre_begin || in_end < in_begin)
        return NULL;
    
    TreeNode* root = new TreeNode(inorder[in_begin]);
    int left_subtree_cnt = 0;
    size_t pre_root_index = pre_begin;
    for (size_t i = pre_begin; i < pre_end; ++i)
    {
        if (preorder[i] == inorder[in_begin])
        {
            pre_root_index = i;
            break;
        }
        left_subtree_cnt++;
    }
    
    root->left = buildHelperPreIn(preorder, inorder, pre_begin, pre_root_index-1, in_begin+1, in_begin+left_subtree_cnt); 
    root->right = buildHelperPreIn(preorder, inorder, pre_root_index+1, pre_end, in_begin+1+left_subtree_cnt, in_end);
    return root; 
}

//通过树的前序和中序遍历结果重新构建一个二叉树
TreeNode* buildTreePreIn(std::vector<int>& preorder, std::vector<int>& inorder)
{
    return buildHelperPreIn(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1); 
}

void PreOrderTraverse(TreeNode* root)
{
    if (NULL == root)
        return;
    PreOrderTraverse(root->left);
    std::cout << root->val << " ";
    PreOrderTraverse(root->right);
}

void InOrderTraverse(TreeNode* root)
{
    if (NULL == root)
        return;
    std::cout << root->val << " ";
    InOrderTraverse(root->left);
    InOrderTraverse(root->right);
}

void PostOrderTraverse(TreeNode* root)
{
    if (NULL == root)
        return;
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    std::cout << root->val << " ";
}

#endif
