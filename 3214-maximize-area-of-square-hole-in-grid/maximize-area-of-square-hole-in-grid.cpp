class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        n = hBars.size();
        m = vBars.size();
        int hMax = 1;
        int vMax = 1;
        int currH = 1;
        int currV = 1;
        for (int i = 1; i < n; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                currH++;
            } else {
                currH = 1;
            }
            hMax = max(hMax, currH);
        }
        for (int i = 1; i < m; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                currV++;
            } else {
                currV = 1;
            }
            vMax = max(vMax, currV);
        }
        int side = min(vMax, hMax) + 1;
        return side * side;
    }
};