/*
	Rotate Image
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

/**
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int N = matrix.size();
        for(int i = 0;i < matrix.size()/2;i++){
            MoveNArround(matrix, i, i, N,N-1);
            N -= 2;
        }
    }
    void MoveNArround(vector<vector<int> >& matrix, int x, int y, int n, int N)
    {
        while(N--){
            MoveOneArround(matrix, x, y,n);
        }
    }
    void MoveOneArround(vector<vector<int> >& matrix, int x, int y, int n){
        if(n <= 1)
            return;
        int tmp = matrix[x][y];
        for(int i = x;i < x+n-1;i++)
            matrix[i][y] = matrix[i+1][y];
        for(int i = y;i < y+n-1;i++)
            matrix[x+n-1][i] = matrix[x+n-1][i+1];
        for(int i = x+n-1;i > x;i--)
            matrix[i][y+n-1] = matrix[i-1][y+n-1];
        for(int i = y+n-1;i > y+1;i--)
            matrix[x][i] = matrix[x][i-1];
        matrix[x][y+1] = tmp;
    }
};
*/

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if(n == 0)
            return;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n-i-1;j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][n-1-i];
            matrix[n-1-j][n-1-i] = tmp;
        }
        for(int i = 0;i < n/2;i++)
            for(int j = 0;j < n;j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-i-1][j];
            matrix[n-i-1][j] = tmp;
        }
    }
};


int main()
{
	const int N = 4;
	int data[N][N] = {{1,2,3,4},{5,6,7,8}, {9,10,11,12},{13,14,15,16}};
	vector<vector<int> >nums;
	for(int i = 0;i < N;i++)
    {
        vector<int> tmp;
        for(int j = 0;j < N;j++)
            tmp.push_back(data[i][j]);
        nums.push_back(tmp);
    }
	Solution test;
	test.rotate(nums);
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
            cout<<nums[i][j]<<"  ";
        cout<<endl;
    }
}
