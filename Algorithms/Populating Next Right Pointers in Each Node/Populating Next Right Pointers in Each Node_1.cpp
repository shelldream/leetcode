/**
	Populating Next Right Pointers in Each Node
	Author:Xiaojun Huang
	Date:2015-08-22

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

TreeLinkNode* buildFunc(vector<int>& preorder, int i, int j, vector<int>& inorder, int x, int y)
{
    if(i > j || x > y || i<0 || j<0 || x<0 || y <0 || i>=preorder.size() || j>=preorder.size() || x>=inorder.size() || y>=inorder.size())
        return NULL;
    int root_val = preorder[i];
    TreeLinkNode* root = new TreeLinkNode(root_val);
    int inorder_root_index = x;
    while(inorder[inorder_root_index] != root_val)
        inorder_root_index++; //查找根节点在后序数组中的下标
    int left_tree_node_count = inorder_root_index-x;
    int right_tree_node_count = y-inorder_root_index;
    root->left = buildFunc(preorder, i+1, i+left_tree_node_count, inorder, x, x+left_tree_node_count-1);
    root->right = buildFunc(preorder, i+left_tree_node_count+1, j, inorder, inorder_root_index+1, y);
    return root;
}

TreeLinkNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j = preorder.size()-1;
        int y = inorder.size()-1;
        return buildFunc(preorder, 0, j, inorder, 0, y);
    }
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> now_level;
        queue<TreeLinkNode*> next_level;
        if(!root)
            return;
        now_level.push(root);
        while(!now_level.empty())
        {
            TreeLinkNode* front_node = now_level.front();
            if(front_node->left)
                next_level.push(front_node->left);
            if(front_node->right)
                next_level.push(front_node->right);
            now_level.pop();
            if(now_level.empty())
            {
                front_node->next = NULL;
                while(!next_level.empty())
                {
                    TreeLinkNode* tmp = next_level.front();
                    next_level.pop();
                    now_level.push(tmp);
                }
            }
            else
            {
                TreeLinkNode* next_front_node = now_level.front();
                front_node->next = next_front_node;
            }
        }
    }
};

int main()
{
    int data1[] = {5,3,2,4,8,7,9};
    int data2[] = {2,3,4,5,7,8,9};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeLinkNode* root = buildTree(preorder,inorder);
    Solution solution;
    solution.connect(root);
}
