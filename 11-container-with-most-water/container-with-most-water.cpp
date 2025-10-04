class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1 , maxWater = 0;
        while(left<right){
            int h = min(height[left] , height[right]);
            int width = right-left;
            int area = h*width;
            maxWater = max(maxWater , area);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater ;
    }
};