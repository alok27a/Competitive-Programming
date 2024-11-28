class Solution {
public:
        int longestConsecutive(vector<int>& nums) {
        set<int> sortedNums(nums.begin(), nums.end()); // Store unique, sorted elements
        if (sortedNums.empty()) 
            return 0;
        
        int ans = 1;
        int count = 1;
        auto it = sortedNums.begin();
        int prev = *it;
        ++it;

        for (; it != sortedNums.end(); ++it) {
            if (*it == prev + 1) { // Consecutive element
                count++;
                ans = max(ans, count);
            } else {
                count = 1; // Reset count for a new sequence
            }
            prev = *it; // Update the previous element
        }

        return ans;
    }
};