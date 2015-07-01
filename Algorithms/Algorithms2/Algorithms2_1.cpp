/*
	Add Two Numbers
	Author:Xiaojun Huang
	Date:2015-3-11
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		int low_digit = 0;
		while(l1 && l2)
		{
			int sum = l1->val+l2->val+low_digit;
			int now_digit = sum%10;
			low_digit = sum/10;
			l1 = l1->next;
			l2 = l2->next;
			ListNode* node = new ListNode(now_digit);
			tail->next= node;
			tail = node;	
		}        
		while(l1)
		{
			int sum = l1->val+low_digit;
			int now_digit = sum%10;
			low_digit = sum/10;
			l1 = l1->next;
			ListNode* node = new ListNode(now_digit);
			tail->next = node;
			tail = node;
		}
		while(l2)
		{
			int sum = l2->val+low_digit;
			int now_digit = sum%10;
			low_digit = sum/10;
			l2 = l2->next;
			ListNode* node = new ListNode(now_digit);
			tail->next = node;
			tail = node;
		}	
		if(low_digit)
		{
			ListNode* node = new ListNode(low_digit);
			tail->next = node;
			tail = node;
		}	
		ListNode* toDel = head;
		head = head->next;
		delete toDel;
		return head;
    }
};

ListNode* vector2List(vector<int> &numbers)
{
	ListNode* head = new ListNode(0);
	ListNode* tail = head;
	int size = numbers.size();
	for(int i = 0;i < size;i++)
	{
		ListNode* node = new ListNode(numbers[i]);
		tail->next = node;
		tail = node;	
	}
	ListNode* toDel = head;
	head = head->next;
	delete toDel;
	return head;
} 

void printList(ListNode* head){
	ListNode* p = head;
	while(p){
		cout<<p->val<<endl;
		p = p->next;
	}
}

int main(){
	int data1[] = {2,4,3};
	int data2[] = {5,6,4};
	int size1 = sizeof(data1) / sizeof(data1[0]);
	int size2 = sizeof(data2) / sizeof(data2[0]);
	vector<int> test1(data1,data1+size1);
	vector<int> test2(data2,data2+size2);
	Solution solution;
	ListNode* ans = solution.addTwoNumbers(vector2List(test1),vector2List(test2));
	printList(ans); 
}

/*说明
1.注意进位
2.注意最高位的处理
*/ 