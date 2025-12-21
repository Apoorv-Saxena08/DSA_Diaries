class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        // sorted[i] = true means
        // strs[i] < strs[i+1] already confirmed ho chuka hai
        vector<bool> sorted(n - 1, false);
        
        int deletions = 0;

        // har column left se right check karo
        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // adjacent rows compare karo
            for (int i = 0; i < n - 1; i++) {
                // agar pehle se sorted nahi hai (equal chal rahe the)
                // aur current column mein order galat mil gaya
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            // agar column delete karni hai toh skip update
            if (needDelete) {
                deletions++;
                continue; // next column par jao
            }

            // warna agar column rakha hai, toh sorted relations update karo
            for (int i = 0; i < n - 1; i++) {
                // Agar strictly less mil gaya, toh aage ke columns 
                // is pair ke liye matter nahi karte
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return deletions;
    }
};