class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& c) {
        int sum = 0;
        for(int i : apple){
            sum += i;
        }
        sort(c.begin(),c.end());
        // vector<int>pre(c.size(),c[0]);
        // for(int i = 1 ; i<c.size();i++){
        //     pre[i] = c[i]+pre[i-1];
        // }

        int count = 0;
        for(int i = c.size()-1;i>=0;i--){
            if(sum>c[i]){
                count++;
                sum = sum - c[i];
            }
            else{
                //== or less than
                count++;
                break;
            }
        }
        return count;
    }
};