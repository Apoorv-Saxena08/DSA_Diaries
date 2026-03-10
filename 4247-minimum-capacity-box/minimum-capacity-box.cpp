class Solution {
public:
    int minimumIndex(vector<int>& c, int sz) {
        vector<int>a(c.begin(),c.end());
        sort(a.begin(),a.end());
        int mini = INT_MAX;
        for(int i : a){
            if(i>=sz){
                mini = min(mini,i);
            }
        }
        if(mini==INT_MAX)return -1;

        for(int i=0;i<c.size();i++){
            if(c[i]==mini)return i;
        }
        return -1;
    }
};