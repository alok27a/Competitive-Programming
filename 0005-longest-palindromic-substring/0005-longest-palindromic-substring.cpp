class Solution {
public:
    
    bool isPalindrome(const string &str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    
     string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;  // If the string length is less than 2, return it as is.

        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());  // Reverse the string to compare.

        // Create a 2D DP table to store lengths of longest common suffixes
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int longestLength = 0;  // Length of the longest palindromic substring.
        int endIndex = 0;       // Ending index of the longest palindromic substring.

        // Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // Check if it forms a palindrome and if it's the longest found so far.
                    if (dp[i][j] > longestLength && isPalindrome(s1.substr(i - dp[i][j], dp[i][j]))) {
                        longestLength = dp[i][j];
                        endIndex = i;  // Update the end index
                    }
                } else {
                    dp[i][j] = 0;  // No common substring.
                }
            }
        }

        // Extract the longest palindromic substring
        return s1.substr(endIndex - longestLength, longestLength);
    }

};