class Solution {
public:
    bool canEat(vector<int>& piles, int h , int speed){
        long long hours = 0;

        for(int p : piles){
            hours += ceil( (double)p / speed );
        }

        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = *max_element(piles.begin() , piles.end());

        while(l<=r){
            int mid = l + (r-l)/2;

            if(canEat(piles , h , mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return l;
    }
};