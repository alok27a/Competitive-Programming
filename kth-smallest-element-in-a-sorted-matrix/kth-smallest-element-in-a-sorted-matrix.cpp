class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i,j,n=matrix.size(),m=matrix[0].size(); //n- Row m-Column
        vector<int> output;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                output.push_back(matrix[i][j]);
            }
        }
        sort(output.begin(),output.end());
        return output[k-1];
    }
};