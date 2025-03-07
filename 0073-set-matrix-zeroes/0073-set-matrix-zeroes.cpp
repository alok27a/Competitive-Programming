class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Rows
        int m = matrix[0].size(); // Columns

        vector<int> rows(n,-1);
        vector<int> cols(m,-1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rows[i]==1 || cols[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};