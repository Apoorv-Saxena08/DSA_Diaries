class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        //sort -> Ht descend and if same -> k ascend
        sort(people.begin() , people.end() , [](vector<int>&a , vector<int>&b){
            if(a[0] == b[0]){
                return a[1]<b[1]; //k ascend
            }

            return a[0] > b[0]; //ht descemd 
        });

        vector<vector<int>>res;

        for(auto&p : people){
            res.insert(res.begin()+p[1] , p);
        }

        return res;

    }
};