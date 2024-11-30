class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq; // Frequency map for the current substring
            int maxi = 0; // Maximum frequency in the current substring
            
            // Iterate over all possible ending points
            for (int j = i; j < n; j++) {
                freq[s[j]]++; // Update frequency of the current character
                maxi = max(maxi, freq[s[j]]); // Update maximum frequency
                
                int mini = INT_MAX;
                for (auto& p : freq) {
                    mini = min(mini, p.second); // Find the minimum frequency
                }
                
                ans += (maxi - mini); // Add beauty value of the current substring
            }
        }

        return ans;
    }
};
