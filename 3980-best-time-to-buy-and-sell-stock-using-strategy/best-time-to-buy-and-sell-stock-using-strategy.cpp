class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half_k = k / 2;
        
        long long base_profit = 0;
        for (int i = 0; i < n; ++i) {
            base_profit += (long long)strategy[i] * prices[i];
        }
        
        long long max_profit = base_profit;
        
        long long current_window_original_profit = 0;
        long long current_second_half_prices = 0;
        
        for (int i = 0; i < k; ++i) {
            current_window_original_profit += (long long)strategy[i] * prices[i];
        }
        for (int i = half_k; i < k; ++i) {
            current_second_half_prices += prices[i];
        }
        
        long long first_window_profit = base_profit - current_window_original_profit + current_second_half_prices;
        if (first_window_profit > max_profit) {
            max_profit = first_window_profit;
        }
        
        for (int i = 1; i <= n - k; ++i) {
            current_window_original_profit -= (long long)strategy[i - 1] * prices[i - 1];
            current_window_original_profit += (long long)strategy[i + k - 1] * prices[i + k - 1];
            
            current_second_half_prices -= prices[i + half_k - 1];
            current_second_half_prices += prices[i + k - 1];
            
            long long current_profit = base_profit - current_window_original_profit + current_second_half_prices;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
        
        return max_profit;
    }
};