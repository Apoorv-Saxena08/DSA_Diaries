class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int search = k;
        for(int n : nums){
            if(n == search){
                search += k;
            }
            else if(n>search){
                return search;;
            }
        }
        return search; // if not present at last 
    }
};