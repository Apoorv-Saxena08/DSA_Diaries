class Solution {
public:
    int solve(int num){
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int d1 = i;
                int d2 = num / i;

                if (d1 == d2) {
                    cnt += 1;
                    sum += d1;
                } else {
                    cnt += 2;
                    sum += d1 + d2;
                }

                if (cnt > 4) return 0; 
            }
        }
        return cnt == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        for(int i = 0 ; i<n;i++){
            ans += solve(nums[i]);
        }
        return ans;
    }
};