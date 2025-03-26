class Solution {
public:
    string reorganizeString(string str) {
        vector<int> hash(26, 0);
        
        // Count frequency of each character
        for (char c : str) {
            hash[c - 'a']++;
        }
        
        int maxFreq = 0, letter = 0;
        
        // Find the character with maximum frequency
        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                letter = i;
            }
        }
        
        // If the max frequency is greater than half of the string length, return an empty string
        if (maxFreq > (str.length() + 1) / 2) {
            return "";
        }
        
        string result(str.length(), ' ');
        int idx = 0;
        
        // Fill even positions with the majority character
        while (hash[letter]-- > 0) {
            result[idx] = letter + 'a';
            idx += 2;
        }
        
        // Fill remaining positions with other characters
        for (int i = 0; i < 26; i++) {
            while (hash[i]-- > 0) {
                if (idx >= result.length()) {
                    idx = 1; // Once even positions are filled, start filling odd positions
                }
                result[idx] = i + 'a';
                idx += 2;
            }
        }
        
        return result;
    }

};