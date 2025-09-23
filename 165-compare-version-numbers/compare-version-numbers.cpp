class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0 , j = 0 , len1 = v1.length() , len2 = v2.length();

        while(i < len1 || j < len2){
            //check all version seperately 
            long num1 = 0 , num2 = 0;

            while(i < len1 && v1[i] != '.'){
                num1 = num1*10 + (v1[i] - '0');//make number
                i++;
            }

            while(j < len2 && v2[j] != '.'){
                num2 = num2*10 + (v2[j] - '0');//make number
                j++;
            }

            if(num1 > num2)return 1;
            if(num1 < num2) return -1;

            i++;
            j++;
        }
        return 0;
    }
};