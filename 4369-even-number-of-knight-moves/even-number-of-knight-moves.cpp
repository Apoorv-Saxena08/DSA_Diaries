class Solution {
public:
    bool visited[8][8][2];//8*8 board with 2 different colors 
    //Horse always change its parity 

    bool solve(int xo, int yo, int xt, int yt, int c) {

        if (xo < 0 || xo > 7 || yo < 0 || yo > 7)
            return false;

        if (visited[xo][yo][c % 2]) //Odd parity ayi to direct false
            return false;

        if (xo == xt && yo == yt)
            return (c % 2 == 0);

        visited[xo][yo][c % 2] = true;

        bool c1 = solve(xo + 1, yo + 2, xt, yt, c + 1);
        bool c2 = solve(xo - 1, yo + 2, xt, yt, c + 1);
        bool c3 = solve(xo + 2, yo + 1, xt, yt, c + 1);
        bool c4 = solve(xo + 2, yo - 1, xt, yt, c + 1);
        bool c5 = solve(xo + 1, yo - 2, xt, yt, c + 1);
        bool c6 = solve(xo - 1, yo - 2, xt, yt, c + 1);
        bool c7 = solve(xo - 2, yo - 1, xt, yt, c + 1);
        bool c8 = solve(xo - 2, yo + 1, xt, yt, c + 1);

        return c1 || c2 || c3 || c4 || c5 || c6 || c7 || c8;
    }

    bool canReach(vector<int>& start, vector<int>& target) {

        memset(visited, false, sizeof(visited));

        int xo = start[0], yo = start[1];
        int xt = target[0], yt = target[1];

        return solve(xo, yo, xt, yt, 0);
    }
};