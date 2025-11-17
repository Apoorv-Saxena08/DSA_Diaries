class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>ones;
        int n = nums.size();
        for(int i=0;i<n;i++ ){
            if(nums[i]==1){
                ones.push_back(i);
            }
        }
        if(ones.size()==0)return true;
        for(int i =0 ; i<ones.size()-1;i++){
            if(ones[i+1]-ones[i]-1 <k){
                return false;
            }
        }
        return true;
    }
};