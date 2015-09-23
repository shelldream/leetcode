/**
	Gas Station
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_sum = 0;//全局剩油和
        int tmp_sum = 0;//局部剩油和
        int start_pos = 0;
        for(int i = 0;i < gas.size();i++)
        {
            int tmp = gas[i]-cost[i];
            total_sum += tmp;
            if(tmp_sum < 0)
            {
                start_pos = i;
                tmp_sum = tmp;
            }
            else tmp_sum += tmp;
        }
        return (total_sum >= 0) ? start_pos : -1;
    }
};

int main()
{

	int data1[] = {2,3,1};
	int data2[] = {3,1,2};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> gas(data1,data1+n1);
    vector<int> cost(data2,data2+n2);
	Solution test;
	cout<<test.canCompleteCircuit(gas, cost);
}
