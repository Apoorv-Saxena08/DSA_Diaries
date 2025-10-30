class Solution {
public:
    vector<vector<int>>grid;
    void fill(int x , int y , int size , int offset){
        if(size == 1){
            grid[x][y] = offset;
            return ;
        }
        int half = size/2;
        int blocksize = half*half;
        //Q0
        fill(x,y,half,offset + 3*blocksize);
        //Q1
        fill(x,y+half,half,offset);
        //Q2
        fill(x+half,y+half,half,offset + blocksize);
        //Q3
        fill(x+half,y,half, offset + 2*blocksize);
    }

    vector<vector<int>> specialGrid(int n) {
        //cal size : 1<<n;
        int size = 1<<n;
        grid.assign(size , vector<int>(size));
        fill(0,0,size,0);//x y size offset(start value);
        return grid;
    }
};