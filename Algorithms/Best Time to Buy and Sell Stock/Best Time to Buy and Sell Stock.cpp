/**
	Best Time to Buy and Sell Stock
	Author:Xiaojun Huang
	Date:2015-08-27
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int ans = 0;
        int low = prices[0];
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i] < low)
                low = prices[i];
            if(prices[i] - low > ans)
                ans = prices[i] - low;
        }
        return ans;
    }
};

int main()
{
	int data[] = {1,2,6,10,300,-1,-100,10000};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+size);
	Solution solution;
	cout<<solution.maxProfit(nums)<<endl;

}
