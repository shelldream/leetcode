/**
	Palindrome Linked List
	Author:Xiaojun Huang
	Date:2015-09-07

*/

#include <iostream>
#include <vector>
using namespace std;

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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || (head && !head->next))
            return true;
        ListNode* mid_node = get_mid_node(head);
        //cout<<mid_node->val<<"   "<<mid_node->next->val<<endl;
        ListNode* next_half = mid_node->next;
        mid_node->next = NULL;
        ListNode* reversed_next_half = reverseList(next_half);
        return isListSame(head,reversed_next_half);
    }
    ListNode* get_mid_node(ListNode* head)
    {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast)
        {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else break;
            if(!fast)
                break;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* ans = NULL;
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = NULL;
            if(!ans)
            {
                ans = head;
            }
            else
            {
                head->next = ans;
                ans = head;
            }
            head = tmp;
        }
        return ans;
    }
    bool isListSame(ListNode* p1, ListNode* p2)
    {
        while(p1 && p2)
        {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(!p2)
            return true;
        else return false;
    }
};

int main()
{
    //int data[] = {1,2,3,4,5,4,3,2,1};
    //int data[] = {1,2,3,4,5,5,4,3,2,1};
    //int data[] = {1,2,3,4,5,4,3,2};
    int data[] = {1,0};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    //print_list(L1);
    Solution solution;
    cout<<solution.isPalindrome(L1)<<endl;
}
