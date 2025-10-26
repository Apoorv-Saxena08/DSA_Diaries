// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        int ans = 0;
        for(int i = 0 ; i<arr.size();i++){
            ans += arr[i];
        }
        return ans;
    }
};