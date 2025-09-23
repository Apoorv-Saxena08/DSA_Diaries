class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int f) {
        int n = bed.size();
        for(int i = 0 ; i< n ; i++){
            bool leftside = (i==0) || bed[i-1] == 0;
            bool rightside = (i==n-1) || bed[i+1] == 0;
            if(leftside && rightside && bed[i]==0){
                bed[i] = 1;
                f--;
            }
        }
        return f<=0;
    }
};