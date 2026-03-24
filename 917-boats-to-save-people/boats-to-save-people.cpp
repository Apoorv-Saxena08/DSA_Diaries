class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size() , i = 0 , j = n-1, ans = 0;
        sort(people.begin() , people.end());
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }else{
                j--; //heavy vala akele jayega
            }

            ans++;
        }

        return ans;
    }
};