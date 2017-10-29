/*
	Description:
        Implement Queue using Stacks
        https://leetcode.com/problems/implement-queue-using-stacks/description/
    Author: shelldream
	Date:2017-10-29
*/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _stack_tail.push(x);
    }   

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int peek_num = peek();
        _stack_head.pop();
        return peek_num;
    }   

    /** Get the front element. */
    int peek() {
        if (_stack_head.empty())
        {   
            while(!_stack_tail.empty())
            {   
                _stack_head.push(_stack_tail.top());
                _stack_tail.pop();        
            }   
        }   
        return _stack_head.top();    
    }   

    /** Returns whether the queue is empty. */
    bool empty() {
        return _stack_tail.empty() && _stack_head.empty();
    }   

private:
    stack<int> _stack_tail;
    stack<int> _stack_head;
};

int main()
{
    Solution solution;

}

