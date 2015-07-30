/*
	Reverse Linked List
	Author:Xiaojun Huang
	Date:2015-07-30

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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans=NULL;
        while(head)
        {
            ListNode* next_node = head->next;
            if(ans)
                head->next = ans;
            else
                head->next = NULL;
            ans = head;
            head = next_node;
        }
        return ans;
    }
};

int main()
{
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    print_list(solution.reverseList(L1));

}

/*
หตร๗


*/
