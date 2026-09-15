class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        string m = s + s;
        int c = 0;

        for(int i = 0; i < n; i++) {
            int score = 0;

            for(int j = i; j < i + n - 1; j++) {
                if(m[j] == m[j + 1])
                    score++;
            }

            if(score == k)
                c++;
        }

        return c;
    }
};