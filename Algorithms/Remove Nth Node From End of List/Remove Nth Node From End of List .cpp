/*
	Remove Nth Node From End of List
	Author:Xiaojun Huang
	Date:2015-07-23

*/

#include <iostream>
#include <algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode* pre = head;
        ListNode* post = head;
        int count = 1;
        while(count<=n && pre)
        {
            pre = pre->next;
            count++;
        }
        while(pre && pre->next)
        {
            post = post->next;
            pre = pre->next;
        }
        ListNode* to_del;
        if(!pre)//删除的是头结点
        {
            to_del = head;
            head = head->next;
        }
        else
        {
            to_del = post->next;
            post->next = to_del->next;
        }
        delete to_del;
        return head;
    }
};

int main()
{
    int data[] = {-1,2,2,-5,0,-1,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    print_list(solution.removeNthFromEnd(L1,7));

}

/*
说明


*/
