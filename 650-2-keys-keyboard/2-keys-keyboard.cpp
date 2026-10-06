class Solution {
public:
    int mini = INT_MAX;

    void solve(int &curr, int &copy, int n, int &op) {
        if (curr == n) {
            mini = min(mini, op);
            return;
        }

        if (curr > n) return;
        //copy all
        if (copy != curr) {
            int newCopy = curr;
            int newOp = op + 1;
            solve(curr, newCopy, n, newOp);
        }

        // Paste
        if (copy != 0) {
            int newCurr = curr + copy;
            int newOp = op + 1;
            solve(newCurr, copy, n, newOp);
        }
    }

    int minSteps(int n) {
        if (n == 1) return 0;

        mini = INT_MAX;
        int curr = 1;
        int copy = 0;
        int op = 0;

        solve(curr, copy, n, op);

        return mini;
    }
};