class Solution {
public:
    int countTriples(int n) {
        int c = 0;
        for(int i = 1; i<=n;i++){
            for(int j = 1 ; j<=n;j++){
                if(j==i){
                    continue;
                }
                else{
                    for(int k = 1 ; k<=n;k++){
                        if(k==j){
                            continue;
                        }
                        else{
                            int sum = i*i + j*j;
                            if(sum == k*k){
                                c++;
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};