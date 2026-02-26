class Solution {
  public:
  
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        string word;   // store full word
        
        TrieNode() {
            isEnd = false;
            word = "";
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    
    void insert(TrieNode* root, string &word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'A';
            if(node->child[idx] == NULL)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
        node->word = word;
    }
    
    
    void dfs(int x, int y,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             TrieNode* node,
             set<string>& result) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        if(x < 0 || y < 0 || x >= r || y >= c)
            return;
        
        if(visited[x][y])
            return;
        
        char ch = grid[x][y];
        
        if(node->child[ch - 'A'] == NULL)
            return;
        
        node = node->child[ch - 'A'];
        
        if(node->isEnd) {
            result.insert(node->word);
        }
        
        visited[x][y] = true;
        
        for(int d = 0; d < 8; d++) {
            dfs(x + dx[d], y + dy[d], grid, visited, node, result);
        }
        
        visited[x][y] = false;
    }
    
    
    vector<string> openGates(vector<vector<char>>& grid,
                             vector<string>& gate_names) {
        
        TrieNode* root = new TrieNode();
        
        // Remove duplicates automatically using set
        set<string> uniqueWords(gate_names.begin(), gate_names.end());
        
        for(string word : uniqueWords)
            insert(root, word);
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        set<string> result;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                dfs(i, j, grid, visited, root, result);
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
};