class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 1) {
            //cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return 1;
        }
        
        int moves = 0;
        moves += towerOfHanoi(n - 1, from, aux, to);
        //cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        moves += 1;
        moves += towerOfHanoi(n - 1, aux, to, from);
        
        return moves;
    }
};
