/**
	Happy Number
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        else
        {
            int sq_sum = 0;
            while(n)
            {
                int tmp = n%10;
                n /= 10;
                sq_sum += tmp*tmp;
            }
            if(my_map.count(sq_sum) > 0)
                return false;
            my_map[sq_sum] = 1;
            return isHappy(sq_sum);
        }

    }
private:
    map<int,int> my_map;
};

int main()
{
    Solution test;
    cout<<test.isHappy(19)<<endl;
}
