class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)return 1;
        
        priority_queue<long , vector<long> ,greater<long> >pq;
        unordered_set<long>used;

        pq.push(1);
        used.insert(1);

        long ans = 1;

        for(int i = 1 ; i<=n ; i++){
            ans = pq.top();
            pq.pop();

            long two = ans*2;
            long three = ans*3;
            long five = ans*5;
            
            if(!used.count(two)){
                pq.push(two);
                used.insert(two);
            }
            if(!used.count(three)){
                pq.push(three);
                used.insert(three);
            }
            if(!used.count(five)){
                pq.push(five);
                used.insert(five);
            }
        }

        return ans;

    }
};