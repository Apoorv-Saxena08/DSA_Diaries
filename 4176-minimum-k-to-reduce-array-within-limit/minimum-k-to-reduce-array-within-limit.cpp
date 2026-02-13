class Solution {
public:
    bool valid (long long mid ,vector<int>& nums ){
        long long op = 0;
        for(int i : nums){
            op += (i + mid - 1) / mid; //ceil vala division

            if (op > mid * mid)   // early stop
                return false;
        }
        return op<= (mid*mid);
    }

    int minimumK(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n = nums.size() , maxi = 100000;
        
        long long  l = 1 , e = maxi ;
        long long  ans = e;
        while(l<=e){
            long long mid = l + (e - l) / 2;
            if(valid(mid,nums)){
                ans = mid;
                e = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};