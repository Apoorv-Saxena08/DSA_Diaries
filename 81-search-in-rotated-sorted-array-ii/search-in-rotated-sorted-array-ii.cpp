class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() , l = 0  , r = n-1;

        while(l<r){
            int mid = l + (r-l)/2;
            //left half sorted
            if(nums[mid] > nums[r] ){
                //range check kr
                if(nums[l]<= target && target <= nums[mid]){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            else if (nums[mid] < nums[r]){
                //right half sorted 
                if(nums[mid]<target && target <= nums[r]){
                    l = mid+1;
                }else{
                    r = mid;
                }
            }else{
                //ki unambiguity , duplicate elem 
                --r;
            }
        }

        return nums[l] == target;
    }
};