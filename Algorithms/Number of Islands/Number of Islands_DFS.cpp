/*
	Number of Islands
	Author:Xiaojun Huang
	Date:2015-08-01
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int ans = 0;
        rows = grid.size();
        if(rows == 0)
            return 0;
        columns = grid[0].size();
        vector<vector<bool> > isVisited;
        for(int i = 0;i < rows;i++)
        {
            vector<bool> tmp;
            for(int j = 0;j < columns;j++)
                tmp.push_back(false);
            isVisited.push_back(tmp);
        }
        for(int i = 0;i < rows;i++)
            for(int j = 0;j < columns;j++)
            {
                //cout<<i<<"  "<<j<<" "<<grid[i][j]<<" "<<isVisited[i][j]<<endl;
                if(grid[i][j] == '1' && !isVisited[i][j])
                {

                    ans++;
                    DFS(grid,i,j,isVisited);
                }
            }
        return ans;
    }
    void DFS(vector<vector<char> >& grid,int x,int y,vector<vector<bool> >& isVisited)
    {
        if(isVisited[x][y])
            return;
        isVisited[x][y] = true;
        int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0;i < 4;i++)
        {
            int next_x = x+direction[i][0];
            int next_y = y+direction[i][1];
            if(next_x>=0 && next_x<rows && next_y>=0 && next_y<columns &&
                                                        !isVisited[next_x][next_y] && grid[next_x][next_y] == '1')
            {
                DFS(grid, next_x,next_y,isVisited);

            }
        }
    }
private:
    int rows;
    int columns;
};


int main()
{
    //string data[4] = {"11110", "11010", "11000", "00000"};
    string data[4] = {"11000", "11000", "00100", "00011"};
    vector<vector<char> > grid;
    for(int i = 0;i < 4;i++)
    {
        vector<char> tmp;
        for(int j = 0;j < 5;j++)
            tmp.push_back(data[i][j]);
        grid.push_back(tmp);
    }
    Solution solution;
    cout<<solution.numIslands(grid)<<endl;
}
