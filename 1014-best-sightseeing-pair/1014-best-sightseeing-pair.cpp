class Solution {
public:
    
     int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if (n == 2) 
            return values[0] + values[1] - 1;

        // Initialize variables
        int maxScore = INT_MIN;
        int maxLeft = values[0]; // Tracks the maximum "values[i] + i" seen so far

        // Iterate through the array starting from the second element
        for (int j = 1; j < n; j++) {
            // Update the maximum score for the pair (i, j)
            maxScore = max(maxScore, maxLeft + values[j] - j);

            // Update maxLeft for the next iteration
            maxLeft = max(maxLeft, values[j] + j);
        }

        return maxScore;
    }


};