class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() , start = 0 , end = 0 , mid , ans ;
        long long sum = 0;
        for(int i : piles){
            sum += i;
            end = max(end , i);
        }
        //defined search space
        start = sum/h;
        if(start == 0)start = 1;

        while(start <= end){
            int mid = start + (end-start)/2;
            int total = 0;
            for(int i = 0 ; i<n;i++){
                total += piles[i]/mid;
                if(piles[i]%mid)total++;
            }

            if(total<=h){
                //left jao 
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;
    }
};