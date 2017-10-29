/*
	Description:
        Implement Stack using Queues
        https://leetcode.com/problems/implement-stack-using-queues/description/
    Author: shelldream
	Date:2017-10-29
*/
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!_queue_one.empty())
            _queue_one.push(x);    
        else
            _queue_two.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (!_queue_one.empty())
        {
            while(!_queue_one.empty())
            {
                res = _queue_one.front();
                _queue_one.pop();
                if (!_queue_one.empty())
                    _queue_two.push(res);
            }
            return res;
        }
        else
        {
            while(!_queue_two.empty())
            {
                res = _queue_two.front();
                _queue_two.pop();
                if (!_queue_two.empty())
                    _queue_one.push(res);
            }
            return res;
        }
    }

    /** Get the top element. */
    int top() {
        int res;
        if (!_queue_one.empty())
        {
            while(!_queue_one.empty())
            {
                res = _queue_one.front();
                _queue_one.pop();
                _queue_two.push(res);
            }
            return res;
        }
        else
        {
            while(!_queue_two.empty())
            {
                res = _queue_two.front();
                _queue_two.pop();
                _queue_one.push(res);
            }
            return res;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _queue_one.empty() && _queue_two.empty();
    }

private:
    queue<int> _queue_one;
    queue<int> _queue_two;
};


int main()
{
    MyStack my_stack;
    my_stack.push(1);
    my_stack.push(2);

}
