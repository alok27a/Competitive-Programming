class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//         Taking a transpose 
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j>i)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        
//         Reverseing each row now
        
         for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};