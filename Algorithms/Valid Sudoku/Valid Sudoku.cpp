/**
	Valid Sudoku
	Author:Xiaojun Huang
	Date:2015-09-10

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int m = board.size();
        if(!m)
            return true;
        int n = board[0].size();
        for(int i = 0;i <= m-3;i += 3)
            for(int j = 0;j <= n-3;j += 3)
        {
            if(!isSubValid(board,i,j))
                return false;
        }
        if(isRowValid(board) && isColumnValid(board))
            return true;
        else
        {
            cout<<"fdsadfsdf"<<endl;
            return false;
        }
    }
    bool isRowValid(vector<vector<char> >&board)
    {
        for(int i = 0;i < board.size();i++)
        {
            int num[10] = {0};
            for(int j = 0;j < board[i].size();j++)
            {
                if(board[i][j] != '.')
                {
                    int x = board[i][j]-'0';
                    if(num[x] == 0)
                        num[x] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }
    bool isColumnValid(vector<vector<char> >&board)
    {
        for(int i = 0;i < board[0].size();i++)
        {
            int num[10] = {0};
            for(int j = 0;j < board.size();j++)
            {
                if(board[j][i] != '.')
                {
                    int x = board[j][i]-'0';
                    if(num[x] == 0)
                        num[x] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }
    bool isSubValid(vector<vector<char> >& board, int i ,int j)
    {
        int num[10] = {0};
        for(int m = i;m <= i+2;m++)
            for(int n = j;n <= j+2;n++)
        {
            if(board[m][n] != '.')
            {
                int x = board[m][n]-'0';
                if(num[x] == 0)
                    num[x] = 1;
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    //string data[] = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
    string data[] = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
    int m = sizeof(data)/sizeof(data[0]);
    int n = data[0].size();
    vector<vector<char> > board;
    for(int i = 0;i < m;i++)
    {
        vector<char> tmp;
        for(int j = 0;j < n;j++)
            tmp.push_back(data[i][j]);
        board.push_back(tmp);
    }
    Solution test;
    cout<<test.isValidSudoku(board)<<endl;
}
