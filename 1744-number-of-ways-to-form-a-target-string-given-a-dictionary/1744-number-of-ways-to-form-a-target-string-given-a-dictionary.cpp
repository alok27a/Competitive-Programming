class Solution {
public:

    int mod = 1e9 + 7;
    long long solve(vector<string>& words, string target, int i,int j,int n, int m,vector<unordered_map<char, int>> &freq, vector<vector<int>> &dp)
    {
        if(j==m) return 1;
        if(i==n) return 0;

        if(dp[i][j]!= -1) return dp[i][j]; 

        // Not take
        long long exc = solve(words,target,i+1,j,n,m,freq,dp);
        // Take
        long long inc = 0;
        if(freq[i][target[j]]> 0){
            int count = freq[i][target[j]];
            inc = (count*solve(words,target,i+1,j+1,n,m,freq,dp))%mod;
        }
        return dp[i][j] = (inc + exc)%mod;
    }

    long long solve_tab(vector<string>& words, string target, int i, int j, int n, int m, vector<unordered_map<char, int>>& freq, vector<vector<int>>& dp) {
        const int mod = 1e9 + 7;
        vector<vector<long long>> table(n + 1, vector<long long>(m + 1, 0));

        for (int k = 0; k <= n; k++) {
            table[k][m] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                long long exc = table[i + 1][j];
                long long inc = 0;
                if (freq[i][target[j]] > 0) {
                    int count = freq[i][target[j]];
                    inc = (count * table[i + 1][j + 1]) % mod;
                }

                table[i][j] = (inc + exc) % mod;
            }
        }
        return table[i][j];
    }


    int numWays(vector<string>& words, string target) {
        // Creating the frequency dictionary 
        int n = words[0].size();
        int m = target.size();

        vector<unordered_map<char, int>> freq(n);

        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                freq[i][word[i]]++;
            }
        }

        // Veryfying freq array
        for (const auto& map : freq) {
            for (const auto& entry : map) {
                cout << entry.first << ":" << entry.second << " ";
            }
            cout << endl;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve_tab(words,target,0,0,n,m,freq,dp);
        
    }
};