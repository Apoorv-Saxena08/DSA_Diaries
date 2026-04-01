class Solution {
  public:
  
  long long merge(vector<int> &arr , int l , int r , int mid){
      vector<int> temp;
        int i = l, j = mid + 1;
        long long inv = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv += (mid - i + 1); 
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }

        return inv;
  }
  
    long long ms(vector<int> &arr , int l , int r){
        if(l>=r)return 0;
        
        long long inv = 0;
        
        int mid  = l + (r-l)/2;
        
        inv += ms(arr,l,mid);
        inv += ms(arr,mid+1,r);
        inv += merge(arr,l,r,mid);
        
        return inv;
    }
  
    int inversionCount(vector<int> &arr) {
        return ms(arr,0,arr.size() -1);
    }
};