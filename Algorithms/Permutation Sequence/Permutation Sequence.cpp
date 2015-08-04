/*
	Permutation Sequence
	Author:Xiaojun Huang
	Date:2015-08-04

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int k_th;
    long  factorial(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        else return n*factorial(n-1);
    }
    string getPermutation(int n, int k) {
        char permutation[10];
        bool isUsed[10];
        k_th = 0;
        for(int j = 1;j <= n;j++)
            isUsed[j] = false;
        backtrace(0, n, k, permutation, isUsed);
        string ans = permutation;
        return ans;
    }
    void backtrace(int n_th, int n, int k, char* permutation, bool* isUsed)
    {
        if(factorial())
        if(k_th >= k)
            return;
        if(n_th == n)
        {
            k_th++;
            permutation[n] = '\0';
        }
        else
        {
            for(int i = 1;i <= n;i++)
            {
                if(k_th >= k)
                    break;
                if(!isUsed[i])
                {
                    permutation[n_th] = '0' + i;
                    isUsed[i] = true;
                    backtrace(n_th+1, n, k, permutation, isUsed);
                    isUsed[i] = false;
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    cout<<solution.factorial(7)<<endl;
    cout<<solution.getPermutation(8,5590);
}
