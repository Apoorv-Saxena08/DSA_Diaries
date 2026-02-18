class MedianFinder {
public:
    // Max heap (left half)
    priority_queue<int> left;

    // Min heap (right half)
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: Push into max heap
        left.push(num);

        // Step 2: Ensure ordering property
        right.push(left.top());
        left.pop();

        // Step 3: Balance sizes
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
