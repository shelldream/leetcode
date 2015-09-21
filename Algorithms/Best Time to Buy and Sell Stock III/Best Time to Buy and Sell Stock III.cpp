/**
	Best Time to Buy and Sell Stock III
	Author:Xiaojun Huang
	Date:2015-09-21
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<int> inOrderMax(prices.size(), 0);
        vector<int> reverseOrderMax(prices.size(), 0);
        int minPrice = prices[0];
        inOrderMax[0] = 0;
        int current_ans = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i] - minPrice > current_ans)
                current_ans = prices[i]-minPrice;
            inOrderMax[i] = current_ans;
        }
        int maxPrice = prices[prices.size()-1];
        reverseOrderMax[prices.size()-1] = 0;
        current_ans = 0;
        for(int i = prices.size()-2; i >= 0;i--)
        {
            if(prices[i] > maxPrice)
                maxPrice = prices[i];
            else if(current_ans < maxPrice-prices[i])
                current_ans = maxPrice-prices[i];
            reverseOrderMax[i] = current_ans;
        }
        int ans = 0;
        for(int i = 0;i < prices.size();i++)
        {
            int tmp = inOrderMax[i] + reverseOrderMax[i];
            if(tmp > ans)
                ans = tmp;
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
