/**
	Rectangle Area
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = C-A;
        int y1 = D-B;
        int x2 = G-E;
        int y2 = H-F;
        int s1 = x1*y1;
        int s2 = x2*y2;
        int overlap_x = 0;
        if(A >= E && A <= G && C >= E && C <= G)
            overlap_x = C-A;
        else if(E >= A && E <= C && G >= A && G <= C)
            overlap_x = G-E;
        else if(E >= A && E <= C && G >= C)
            overlap_x = C-E;
        else if(A >= E && A <= G && C >= G)
            overlap_x = G-A;
        int overlap_y = 0;
        if(B >= F && B <= H && D >= F && D <= H)
            overlap_y = D-B;
        else if(F >= B && F <= D && H >= B && H <= D)
            overlap_y = H-F;
        else if(F >= B && F <= D && H >= D)
            overlap_y = D-F;
        else if(B >= F && B <= H && D >= H)
            overlap_y = H-B;
        cout<<s1<<" "<<s2<<endl;
        return s1+s2-overlap_x*overlap_y;
    }
};

int main()
{
    Solution test;
    cout<<test.computeArea(-3,0,3,4,0,-1,9,2)<<endl;
}
