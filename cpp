nt determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
            int sign = 1;
    int det = 0;
    if(n == 1) return matrix[0][0];
    if(n == 2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    for (int i = 0; i < n; i++) {
        vector<vector<int>> temp_mat(n - 1, vector<int>(n - 1));
        int row = 0;

        for (int j = 1; j < n; j++) {
            int col = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                temp_mat[row][col] = matrix[j][k];
                // cout<<temp_mat[row][col];
                col++;
            }
            // cout<<endl;
            row++;
        }

        det += sign*matrix[0][i]*determinantOfMatrix(temp_mat,n - 1);
        sign *= -1;

    }

    return det;
    } 
