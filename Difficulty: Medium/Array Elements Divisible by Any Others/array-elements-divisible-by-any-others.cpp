class Solution {
	public:
	int cntSpecialNum(vector<int>& arr) {
		// code here
		int n = arr.size();
		
		int maxi = *max_element(arr.begin() , arr.end());
		vector<int>freq(maxi+1 , 0);
		for(int i : arr){
		    freq[i]++;
		}
		
		vector<bool>special(maxi+1, false);
		
		for(int i = 1 ; i <= maxi ; i++){
		    
		    if(freq[i] == 0){
		        continue;
		    }
		    
		    for(int j = i ; j <= maxi ; j += i){
		        if(freq[j] == 0){
		            continue;
		        }
		        
		        if(i == j){
		            if(freq[i] >= 2){
		                special[i] = 1;
		            }
		        }else{
		            special[j] = 1;
		        }
		    }
		    
		}
		
		int ans = 0 ; 
		
		for (int x : arr)
            if (special[x])
                ans++;
                
		return ans;
	}
};
