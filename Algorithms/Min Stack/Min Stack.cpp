/*
	Min Stack
	Author:Xiaojun Huang
	Date:2015-08-31

*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        normal_stack.push(x);
        if(min_stack.empty())
            min_stack.push(x);
        else
        {
            if(x <= min_stack.top())
                min_stack.push(x);
        }
    }

    void pop() {
        if(!normal_stack.empty())
        {
            if(normal_stack.top() == min_stack.top())
                min_stack.pop();
            normal_stack.pop();
        }
    }

    int top() {
        if(!normal_stack.empty())
            return normal_stack.top();
    }

    int getMin() {
        if(!min_stack.empty())
            return min_stack.top();
    }
private:
    stack<int> normal_stack;
    stack<int> min_stack;
};

int main()
{
	MinStack my_stack;
    my_stack.push(3);
    my_stack.push(-2);
    cout<<my_stack.getMin()<<endl;
    my_stack.push(10);
    cout<<my_stack.getMin()<<endl;
    cout<<my_stack.top()<<endl;
}

