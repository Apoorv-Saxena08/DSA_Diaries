class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        vector<int> freq(10, 0);

        int temp = num;
        while (temp) {
            int rem = temp % 10;
            freq[rem]++;
            nums.push_back(rem);
            temp /= 10;
        }
        reverse(nums.begin(), nums.end());
        
        int j = 0;

        for (int i = 9; i >= 0; i--) {
            
            if (freq[i] == 0) continue;

            if (i == nums[j]) {

                // katte chlo
                while (j < nums.size() && nums[j] == i) {
                    j++;
                    freq[i]--;  
                }
                if (freq[i] == 0) continue; 

                // agr j bhaar ho gya tto number already max h 
                if (j >= nums.size()) break;

                // agr number change ho gya ho to piche se i dhudnen nikl jao
                if (nums[j] != i) {
                    int idx = -1;
                    for (int x = nums.size() - 1; x >= 0; x--) {
                        if (nums[x] == i) {
                            idx = x;
                            break;
                        }
                    }
                    swap(nums[j], nums[idx]);
                    break;
                }

            } else {

                // nums[j] < i -> mismatch ho gya , to vhi change krdo
                int idx = -1;
                for (int x = nums.size() - 1; x >= 0; x--) {
                    if (nums[x] == i) {
                        idx = x;
                        break;
                    }
                }
                swap(nums[j], nums[idx]);
                break;
            }
        }

        int ans = 0;
        for (int d : nums) ans = ans * 10 + d;
        return ans;
    }
};
