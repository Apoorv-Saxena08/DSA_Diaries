class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i<n;i++){
            //remove chote elem
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            //out of window htao
            if(dq.front() <= i-k){
                dq.pop_front();
            }

            //if window exits
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};