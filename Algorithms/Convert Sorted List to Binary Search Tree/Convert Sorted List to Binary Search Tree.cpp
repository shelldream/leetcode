/**
	Convert Sorted List to Binary Search Tree
	Author:Xiaojun Huang
	Date:2015-09-11

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* create_list(vector<int> nums)
{
    ListNode* head=NULL;
    ListNode* tail=NULL;
    for(int i = 0;i<nums.size();i++)
    {
        ListNode* p = new ListNode(nums[i]);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
    }
    return head;
}

void traverse(TreeNode* root)
{
    if(root)
    {
        traverse(root->left);
        cout<<root->val<<"  ";
        traverse(root->right);
    }
}
class Solution {
public:
    TreeNode* create_subtree(ListNode* p, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        ListNode* tmp = p;
        int i = start;
        while(i < mid)
        {
            tmp = tmp->next;
            i++;
        }
        TreeNode* root = new TreeNode(tmp->val);
        TreeNode* left_subtree = create_subtree(p,start,mid-1);
        TreeNode* right_subtree = create_subtree(tmp->next,mid+1,end);
        root->left = left_subtree;
        root->right = right_subtree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* p = head;
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
        }
        return create_subtree(head,0,len-1);
    }
};

int main()
{
    //int data[] = {1,2,3,4,5,6,7,8,9,10};
    int data[] = {0,1,2,3};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* head = create_list(nums);
    Solution test;
    TreeNode* root = test.sortedListToBST(head);
    traverse(root);
}

