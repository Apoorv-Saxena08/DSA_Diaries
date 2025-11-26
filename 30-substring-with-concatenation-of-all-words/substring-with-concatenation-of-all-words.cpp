class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordCount = words.size();
        int wordLen = words[0].size();
        int totalLen = wordCount * wordLen;
        vector<int> result;

        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (auto &w : words) wordFreq[w]++;

        for (int start = 0; start <= s.size() - totalLen; start++) {
            unordered_map<string, int> seen;
            int j = 0;

            while (j < wordCount) {
                string current = s.substr(start + j * wordLen, wordLen);
                if (++seen[current] > wordFreq[current])
                    break;
                j++;
            }

            if (j == wordCount)
                result.push_back(start);
        }

        return result;
    }
};
