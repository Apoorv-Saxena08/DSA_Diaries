class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        //vector<int>pre(n,nums[0]);
        int total = 0;
        for(int i : nums){
            total += i;
        }   
        int curr = 0 ;
        for(int i = 0 ; i<n-1;i++){
            curr += nums[i];
            total -= nums[i];
            int diff = abs(total - curr);
            if(diff%2 == 0){
                ans++;
            }
        }
        return ans;
    }
};