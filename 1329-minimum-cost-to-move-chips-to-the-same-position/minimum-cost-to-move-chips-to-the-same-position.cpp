class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCnt = 0 , evenCnt = 0;
        for(int p : position){
            if(p%2){
                oddCnt++;
            }else{
                evenCnt++;
            }
        }

        return min(oddCnt , evenCnt);
    }
};