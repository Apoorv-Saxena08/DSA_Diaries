class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        int maxAns = INT_MIN; // max no of trains at a time 
        int count = 0 ;
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        
        int s = 0  , e = 0;
        while(s<n && e<n){
                if(arr[s] <= dep[e]){
                    count++;
                    maxAns = max(maxAns , count);
                    s++;
                }
                else{
                    count--;
                    e++;
                }
        }
        return maxAns;
    }
};
