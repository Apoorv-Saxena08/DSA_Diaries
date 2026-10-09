class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int maxi = 0;

        for(auto&v : s){
            int size = v.length();
            int count = 0;
            for(int i = 0; i<size ; i++){
                if(v[i] == ' '){
                    count++;
                }
            }
            maxi = max(maxi , count+1);
        }
        return maxi;
    }
};