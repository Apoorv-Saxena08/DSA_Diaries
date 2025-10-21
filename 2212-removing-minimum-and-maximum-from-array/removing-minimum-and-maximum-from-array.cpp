class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN , mini = INT_MAX;
        for(int n : nums){
            maxi= max(maxi , n);
            mini = min(mini,n);
        }
        int n = nums.size();
        int ans = 0;//bcoz n can be 1 
        //find indexes of those 2 elements
        int idx1 , idx2;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == maxi) idx1 = i;
            if(nums[i] == mini) idx2 = i;
        }
        //left side se 
        int left = min(idx1,idx2);
        //right side se
        int right = max(idx1,idx2);

        //i have 3 options : both from front , both from back or from both sides
        int x = right+1;
        int y = n-left;
        int z = (left+1) + (n-right);
        return min({x,y,z});
    }
};