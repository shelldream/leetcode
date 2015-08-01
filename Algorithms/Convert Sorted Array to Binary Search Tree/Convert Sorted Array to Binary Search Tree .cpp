/*
	Convert Sorted Array to Binary Search Tree
	Author:Xiaojun Huang
	Date:2015-08-01

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

void preorderTraversal(TreeNode* root) {//打印先序遍历的结果
        if(root !=NULL )
        {
            cout<<root->val<<" ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
}

void postorderTraversal(TreeNode* root) {//打印后序遍历的结果
        if(root !=NULL )
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout<<root->val<<" ";
        }
}


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return vector2tree(nums,0,nums.size()-1);
    }

    TreeNode* vector2tree(vector<int>& nums,int low,int high)
    {
        if(low > high)
            return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = vector2tree(nums,low,mid-1);
        root->right = vector2tree(nums,mid+1,high);
        return root;
    }
};

int main()
{
    //int data[] = {1,2,3,4,5,6,7,8,9,10};
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    TreeNode* ans = solution.sortedArrayToBST(nums);
    preorderTraversal(ans);
    cout<<endl;
    postorderTraversal(ans);
}
