class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int , vector<int> , greater<int> >pq;//min heap
        int m = nums1.size() , n = nums2.size() ;
        int len = m+n;
        for(int i = 0 ; i<m;i++){
            pq.push(nums1[i]);
        }
        for(int i = 0 ; i<n;i++){
            pq.push(nums2[i]);
        }

        double ans ;
        int val = len/2;
        if(len%2){
            //odd
            for(int i = 0;i<val;i++){
                pq.pop();
            }
            ans = pq.top();
        }else{
            //even
            for(int i = 0 ;i<val-1;i++){
                pq.pop();
            }
            double one = pq.top();
            pq.pop();
            double two = pq.top();
            pq.pop();
            ans = (one+two)/2;
        }

        return ans;

    }
};